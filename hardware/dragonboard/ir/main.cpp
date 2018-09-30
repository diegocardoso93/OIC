#include <chrono>
#include <ctime>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

#include "mraa/common.hpp"
#include "mraa/gpio.hpp"

#define IR_RCV_PIN 33

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
          if (results.rawlen > 66) {
              printf("%lx", results.value);
              exit(0);
          }
          irrecv.resume();
      }
  }
}
