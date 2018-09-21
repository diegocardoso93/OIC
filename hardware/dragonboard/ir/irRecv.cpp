//******************************************************************************
// OIC - Omnidirecional Infrared Center - 2018
// IR Remote NEC Protocol
// Based on https://github.com/z3t0/Arduino-IRremote
//******************************************************************************

#include "IRremote.h"
#include "IRremoteInt.h"

int IRrecv::decode (decode_results *results)
{
	results->rawbuf   = irparams.rawbuf;
	results->rawlen   = irparams.rawlen;

	results->overflow = irparams.overflow;

	if (irparams.rcvstate != STATE_STOP)  return false ;

#if DECODE_NEC
	DBG_PRINTLN("Attempting NEC decode");
	if (decodeNEC(results))  return true ;
#endif

	// decodeHash returns a hash on any input.
	// Thus, it needs to be last in the list.
	// If you add any decodes, add them before this.
	if (decodeHash(results))  return true ;

	// Throw away and start over
	resume();
	return false;
}

IRrecv::IRrecv (int recvpin)
{
	irparams.recvpin = recvpin;
	irparams.blinkflag = 0;
}


// **
// initialization
//
void  IRrecv::enableIRIn ( )
{
	// Initialize state machine variables
	irparams.rcvstate = STATE_IDLE;
	irparams.rawlen = 0;
}

// **
// Return if receiving new IR signals
//
bool  IRrecv::isIdle ( )
{
 return (irparams.rcvstate == STATE_IDLE || irparams.rcvstate == STATE_STOP) ? true : false;
}

// **
// Restart the ISR state machine
//
void  IRrecv::resume ( )
{
	irparams.rcvstate = STATE_IDLE;
	irparams.rawlen = 0;
}

// **
// hashdecode - decode an arbitrary IR code.
// Instead of decoding using a standard encoding scheme
// (e.g. Sony, NEC, RC5), the code is hashed to a 32-bit value.
//
// The algorithm: look at the sequence of MARK signals, and see if each one
// is shorter (0), the same length (1), or longer (2) than the previous.
// Do the same with the SPACE signals.  Hash the resulting sequence of 0's,
// 1's, and 2's to a 32-bit value.  This will give a unique value for each
// different code (probably), for most code systems.
//
// http://arcfn.com/2010/01/using-arbitrary-remotes-with-arduino.html
//
// Compare two tick values, returning 0 if newval is shorter,
// 1 if newval is equal, and 2 if newval is longer
// Use a tolerance of 20%
//
int  IRrecv::compare (unsigned int oldval,  unsigned int newval)
{
	if      (newval < oldval * .8)  return 0 ;
	else if (oldval < newval * .8)  return 2 ;
	else                            return 1 ;
}

// **
// Use FNV hash algorithm: http://isthe.com/chongo/tech/comp/fnv/#FNV-param
// Converts the raw code values into a 32-bit hash code.
// Hopefully this code is unique for each button.
// This isn't a "real" decoding, just an arbitrary value.
//
#define FNV_PRIME_32 16777619
#define FNV_BASIS_32 2166136261

long  IRrecv::decodeHash (decode_results *results)
{
	long  hash = FNV_BASIS_32;

	// Require at least 6 samples to prevent triggering on noise
	if (results->rawlen < 6)  return false ;

	for (int i = 1;  (i + 2) < results->rawlen;  i++) {
		int value =  compare(results->rawbuf[i], results->rawbuf[i+2]);
		// Add value into the hash
		hash = (hash * FNV_PRIME_32) ^ value;
	}

	results->value       = hash;
	results->bits        = 32;
	results->decode_type = UNKNOWN;

	return true;
}
