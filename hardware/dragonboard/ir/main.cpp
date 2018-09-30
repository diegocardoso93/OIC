#include <chrono>
#include <ctime>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

#include "mraa/common.hpp"
#include "mraa/gpio.hpp"

#define IR_RCV_PIN 33

void dumpCode(decode_results *results);

IRrecv irrecv(IR_RCV_PIN);

int main ()
{
  mraa_init();
  // RECEIVE (working)
  irrecv.enableIRIn();
  auto future2 = std::async(isr_timer_ir);

  while (1) {
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
