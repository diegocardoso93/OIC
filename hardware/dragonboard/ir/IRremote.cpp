//******************************************************************************
// OIC - Omnidirecional Infrared Center - 2018
// IR Remote NEC Protocol
// Based on https://github.com/z3t0/Arduino-IRremote
//******************************************************************************

#define IR_GLOBAL
#	include "IRremote.h"
#	include "IRremoteInt.h"
#undef IR_GLOBAL

#include <iostream>
#include <chrono>
#include <iostream>
#include <future>
#include <ctime>

/* mraa headers */
#include "mraa/common.hpp"
#include "mraa/gpio.hpp"

// **
// The match functions were (apparently) originally MACROs to improve code speed
//   (although this would have bloated the code) hence the names being CAPS
// A later release implemented debug output and so they needed to be converted
//   to functions.
// I tried to implement a dual-compile mode (DEBUG/non-DEBUG) but for some
//   reason, no matter what I did I could not get them to function as macros again.
// I have found a *lot* of bugs in the Arduino compiler over the last few weeks,
//   and I am currently assuming that one of these bugs is my problem.
// I may revisit this code at a later date and look at the assembler produced
//   in a hope of finding out what is going on, but for now they will remain as
//   functions even in non-DEBUG mode
//
int  MATCH (int measured,  int desired)
{
 	DBG_PRINT(F("Testing: "));
 	DBG_PRINT(TICKS_LOW(desired), DEC);
 	DBG_PRINT(F(" <= "));
 	DBG_PRINT(measured, DEC);
 	DBG_PRINT(F(" <= "));
 	DBG_PRINT(TICKS_HIGH(desired), DEC);

  bool passed = ((measured >= TICKS_LOW(desired)) && (measured <= TICKS_HIGH(desired)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

// **
// Due to sensor lag, when received, Marks tend to be 100us too long
//
int  MATCH_MARK (int measured_ticks,  int desired_us)
{
	DBG_PRINT(F("Testing mark (actual vs desired): "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F("us vs "));
	DBG_PRINT(desired_us, DEC);
	DBG_PRINT("us"); 
	DBG_PRINT(": ");
	DBG_PRINT(TICKS_LOW(desired_us + MARK_EXCESS) * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(TICKS_HIGH(desired_us + MARK_EXCESS) * USECPERTICK, DEC);

  bool passed = ((measured_ticks >= TICKS_LOW (desired_us + MARK_EXCESS))
                && (measured_ticks <= TICKS_HIGH(desired_us + MARK_EXCESS)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

// **
// Due to sensor lag, when received, Spaces tend to be 100us too short
//
int  MATCH_SPACE (int measured_ticks,  int desired_us)
{
	DBG_PRINT(F("Testing space (actual vs desired): "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F("us vs "));
	DBG_PRINT(desired_us, DEC);
	DBG_PRINT("us"); 
	DBG_PRINT(": ");
	DBG_PRINT(TICKS_LOW(desired_us - MARK_EXCESS) * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(measured_ticks * USECPERTICK, DEC);
	DBG_PRINT(F(" <= "));
	DBG_PRINT(TICKS_HIGH(desired_us - MARK_EXCESS) * USECPERTICK, DEC);

  bool passed = ((measured_ticks >= TICKS_LOW (desired_us - MARK_EXCESS))
                && (measured_ticks <= TICKS_HIGH(desired_us - MARK_EXCESS)));
  if (passed)
    DBG_PRINTLN(F("?; passed"));
  else
    DBG_PRINTLN(F("?; FAILED")); 
 	return passed;
}

// **
// Interrupt Service Routine - Fires every 50uS
// Interrupt code to collect raw data.
// Widths of alternating SPACE, MARK are recorded in rawbuf.
// Recorded in ticks of 50uS [microseconds, 0.000050 seconds]
// 'rawlen' counts the number of entries recorded so far.
// First entry is the SPACE between transmissions.
// As soon as a the first [SPACE] entry gets long:
//   Ready is set; State switches to IDLE; Timing of SPACE continues.
// As soon as first MARK arrives:
//   Gap width is recorded; Ready is cleared; New logging starts
//

void isr_timer_ir()
{

	mraa::Result status;

	mraa::Gpio gpioir(irparams.recvpin);
	status = gpioir.dir(mraa::DIR_IN);
	if (status != mraa::SUCCESS) {
  	printError(status);
   	return;
	}

	while (1) {
	
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		// Read if IR Receiver -> SPACE [xmt LED off] or a MARK [xmt LED on]
	
		uint8_t irdata = (uint8_t)gpioir.read();

		irparams.timer++;  // One more 50uS tick

		if (irparams.rawlen >= RAWBUF)  irparams.rcvstate = STATE_OVERFLOW ;  // Buffer overflow

		switch (irparams.rcvstate) {
			//......................................................................
			case STATE_IDLE: // In the middle of a gap
				if (irdata == MARK) {
					if (irparams.timer < GAP_TICKS)  {  // Not big enough to be a gap.
						irparams.timer = 0;
					} else {
						// Gap just ended; Record duration; Start recording transmission
						irparams.overflow                  = false;
						irparams.rawlen                    = 0;
						irparams.rawbuf[irparams.rawlen++] = irparams.timer;
						irparams.timer                     = 0;
						irparams.rcvstate                  = STATE_MARK;
					}
				}
				break;
			//......................................................................
			case STATE_MARK:  // Timing Mark
				if (irdata == SPACE) {   // Mark ended; Record time
					irparams.rawbuf[irparams.rawlen++] = irparams.timer;
					irparams.timer                     = 0;
					irparams.rcvstate                  = STATE_SPACE;
				}
				break;
			//......................................................................
			case STATE_SPACE:  // Timing Space
				if (irdata == MARK) {  // Space just ended; Record time
					irparams.rawbuf[irparams.rawlen++] = irparams.timer;
					irparams.timer                     = 0;
					irparams.rcvstate                  = STATE_MARK;

				} else if (irparams.timer > GAP_TICKS) {  // Space
						// A long Space, indicates gap between codes
						// Flag the current code as ready for processing
						// Switch to STOP
						// Don't reset timer; keep counting Space width
						irparams.rcvstate = STATE_STOP;
				}
				break;
			//......................................................................
			case STATE_STOP:  // Waiting; Measuring Gap
				if (irdata == MARK)  irparams.timer = 0 ;  // Reset gap timer
				break;
			//......................................................................
			case STATE_OVERFLOW:  // Flag up a read overflow; Stop the State Machine
				irparams.overflow = true;
				irparams.rcvstate = STATE_STOP;
				break;
		}
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::this_thread::sleep_for(std::chrono::microseconds(50-(int)time_span.count()*1000000));
	}

}
