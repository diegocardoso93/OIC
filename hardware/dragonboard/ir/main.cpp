
#include <chrono>
#include <ctime>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

#include "mraa/common.hpp"
#include "mraa/gpio.hpp"

#include <gpiod.hpp>

#define IR_RCV_PIN 33
#define IR_SND_PIN 31

void dumpCode(decode_results *results);

#define NEC_BITSs          32
#define NEC_HDR_MARKs    9000
#define NEC_HDR_SPACEs   4500
#define NEC_BIT_MARKs     560
#define NEC_ONE_SPACEs   1690
#define NEC_ZERO_SPACEs   560
#define NEC_RPT_SPACEs   2250

IRrecv irrecv(IR_RCV_PIN);

void mark (int cycles) {
  ::std::vector<unsigned int> offsets;
  ::std::vector<int> values1, values2;

  offsets.push_back(::std::stoul("35"));
  values1.push_back(::std::stoul("1"));
  values2.push_back(::std::stoul("0"));

  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

  ::gpiod::chip chip("gpiochip0");
  auto lines = chip.get_lines(offsets);

  for (int i=0; i < cycles; i++) {
    // 38khz pulse
    //gpioir.write(1);
	lines.request({
		"gpioset",
		::gpiod::line_request::DIRECTION_OUTPUT,
		0
	}, values1);
        lines.release();
    //std::this_thread::sleep_for(std::chrono::microseconds(2)); // 2,631578947368421e-5
    usleep(13);
    //gpioir.write(0);

        lines.request({
                "gpioset",
                ::gpiod::line_request::DIRECTION_OUTPUT,
                0
        }, values2);
        lines.release();
    usleep(13);
    //std::this_thread::sleep_for(std::chrono::microseconds(2)); // 2,631578947368421e-5
  }

//		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
   //printf("%fa\n", time_span.count());
}

void space (int cycles) {
  ::std::vector<unsigned int> offsets;
  ::std::vector<int> values2;

  offsets.push_back(::std::stoul("35"));
  values2.push_back(::std::stoul("0"));
  ::gpiod::chip chip("gpiochip0");
  auto lines = chip.get_lines(offsets);

  for (int i=0; i < cycles; i++) {
    // 38khz blank
    //gpioir.write(0);
    //usleep(26);
if (i==0) {
        lines.request({
                "gpioset",
                ::gpiod::line_request::DIRECTION_OUTPUT,
                0
        }, values2);
lines.release();
}    
usleep(26);
    //std::this_thread::sleep_for(std::chrono::microseconds(26)); // 2,631578947368421e-5
  }
}

void sendNEC (unsigned long data, int nbits) {

  mark((int)(NEC_HDR_MARKs/26));
  space((int)(NEC_HDR_SPACEs/26));

  for (unsigned long  mask = 1UL << (nbits - 1);  mask;  mask >>= 1) {
    if (data & mask) {
      mark((int)(NEC_BIT_MARKs/26));
      space((int)(NEC_ONE_SPACEs/26));
    } else {
      mark((int)(NEC_BIT_MARKs/26));
      space((int)(NEC_ZERO_SPACEs/26));
    }
  }

  mark((int)(NEC_BIT_MARKs/26));
  space(1);
}


int main ()
{

mraa_init();

  //while(1) {
  //  sendNEC(0x20DF10EF, 32); //0x20DF10EF 0xFB04F708
  //  sleep(5);
  //}

  // RECEIVE (working)
  irrecv.enableIRIn();
  auto future2 = std::async(isr_timer_ir);

  while (1) {
      // \/ dont work due pin toggle latency
      //sendNEC(0x20DF10EF, 32); //0x20DF10EF 0xFB04F708
      //sleep(1);

      decode_results results;

      if (irrecv.decode(&results)) {
          dumpCode(&results);
          printf("\n");
          irrecv.resume();
      }
  }
}

void dumpCode(decode_results *results) {
  printf("unsigned int  ");
  printf("rawData[%d]", results->rawlen - 1);

  for (int i = 1;  i < results->rawlen;  i++) {
    printf("%d", results->rawbuf[i] * USECPERTICK);
    if ( i < results->rawlen-1 ) printf(",");
    if (!(i & 1))  printf(" ");
  }
  printf("};");  // 

  printf("  // %s", results->decode_type == NEC ? "NEC" : "UNKNOWN");
  printf(" ");
  printf("\n");

  printf("unsigned int  data = 0x");
  printf("%lx", results->value);
  printf(";\n");
}
