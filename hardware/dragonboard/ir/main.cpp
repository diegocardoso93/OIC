
#include <chrono>
#include <ctime>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

#define IR_RCV_PIN 33
#define IR_SND_PIN 34

void dumpCode(decode_results *results);

#define NEC_BITSs          32
#define NEC_HDR_MARKs    9000
#define NEC_HDR_SPACEs   4500
#define NEC_BIT_MARKs     560
#define NEC_ONE_SPACEs   1690
#define NEC_ZERO_SPACEs   560
#define NEC_RPT_SPACEs   2250

IRrecv irrecv(IR_RCV_PIN);

void mark (mraa::Gpio gpioir, int cycles) {
  while (int i=0; i < cycles; i++) {
    // 38khz pulse
    gpioir.write(1);
    //std::this_thread::sleep_for(std::chrono::nanoseconds(13157); // 2,631578947368421e-5
    usleep(13);
    gpioir.write(0);
    usleep(13);
    //std::this_thread::sleep_for(std::chrono::nanoseconds(13157); // 2,631578947368421e-5
  }
}

void space (mraa::Gpio gpioir, int cycles) {
  while (int i=0; i < cycles; i++) {
    // 38khz blank
    gpioir.write(0);
    usleep(26);
    //std::this_thread::sleep_for(std::chrono::nanoseconds(26315); // 2,631578947368421e-5
  }
}

void sendNEC (unsigned long data, int nbits) {

  mraa::Result status;
  mraa::Gpio gpioir(IR_SND_PIN);
  status = gpioir.dir(mraa::DIR_OUT);
  if (status != mraa::SUCCESS) {
    printError(status);
    return;
  }

  mark(gpioir, (int)(NEC_HDR_MARKs/26));
  space(gpioir, (int)(NEC_HDR_SPACEs/26));

	for (unsigned long  mask = 1UL << (nbits - 1);  mask;  mask >>= 1) {
		if (data & mask) {
      mark(gpioir, (int)(NEC_BIT_MARKs/26));
      space(gpioir, (int)(NEC_ONE_SPACEs/26));
		} else {
      mark(gpioir, (int)(NEC_BIT_MARKs/26));
      space(gpioir, (int)(NEC_ZERO_SPACEs/26));
		}
	}

  mark(gpioir, (int)(NEC_BIT_MARKs/26));
  space(gpioir, 1);
}


int main ()
{
  while(1) {
    sendNEC(0x20DF10EF, 32); //0x20DF10EF 0xFB04F708
    sleep(5);
  }

  /* RECEIVE (working)
  irrecv.enableIRIn();
  auto future2 = std::async(isr_timer_ir);

  while (1) {
      decode_results results;

      if (irrecv.decode(&results)) {
          dumpCode(&results);
          printf("\n");
          irrecv.resume();
      }
  }*/
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
