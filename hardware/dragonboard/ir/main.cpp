
#include <chrono>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

void dumpCode(decode_results *results);

IRrecv irrecv(33);

int main ()
{
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
