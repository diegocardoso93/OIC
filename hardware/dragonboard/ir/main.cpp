
#include <chrono>
#include <iostream>
#include <future>
#include <unistd.h>

#include "IRremote.h"

void  ircode (decode_results *results);
void  encoding (decode_results *results);
void  dumpCode(decode_results *results);

void timer() {
    for(int i=0;i<10;++i)
    {
        std::cout << (10-i) << '\n';
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
}

IRrecv irrecv(33);

int main ()
{
    auto future = std::async(timer);
    std::cout << "test\n";
    auto future2 = std::async(isr_timer_ir);
    irrecv.enableIRIn();

    while (1) {

        decode_results  results;        // Somewhere to store the results

        if (irrecv.decode(&results)) {  // Grab an IR code
            dumpCode(&results);           // Output the results as source code
            printf("\n");           // Blank line between entries
            irrecv.resume();              // Prepare for the next value
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    //std::this_thread::sleep_for(std::chrono::seconds(10));
    //std::cout << "test2\n";
}


void  ircode (decode_results *results)
{
  // Print Code
  printf("%lx", results->value);
}

void  encoding (decode_results *results)
{
  switch (results->decode_type) {
    default:
    case UNKNOWN:      printf("UNKNOWN");       break ;
    case NEC:          printf("NEC");           break ;
    case SONY:         printf("SONY");          break ;
    case RC5:          printf("RC5");           break ;
    case RC6:          printf("RC6");           break ;
    case DISH:         printf("DISH");          break ;
    case SHARP:        printf("SHARP");         break ;
    case JVC:          printf("JVC");           break ;
    case SANYO:        printf("SANYO");         break ;
    case MITSUBISHI:   printf("MITSUBISHI");    break ;
    case SAMSUNG:      printf("SAMSUNG");       break ;
    case LG:           printf("LG");            break ;
    case WHYNTER:      printf("WHYNTER");       break ;
    case AIWA_RC_T501: printf("AIWA_RC_T501");  break ;
    case PANASONIC:    printf("PANASONIC");     break ;
    case DENON:        printf("Denon");         break ;
  }
}

void  dumpCode(decode_results *results) {
  // Start declaration
  printf("unsigned int  ");          // variable type
  printf("rawData[%d]", results->rawlen - 1);

  // Dump data
  for (int i = 1;  i < results->rawlen;  i++) {
    //printf(results->rawbuf[i] * USECPERTICK, DEC);
    if ( i < results->rawlen-1 ) printf(","); // ',' not needed on last one
    if (!(i & 1))  printf(" ");
  }

  // End declaration
  printf("};");  // 

  // Comment
  printf("  // ");
  encoding(results);
  printf(" ");
  ircode(results);

  // Newline
  printf("\n");

  // Now dump "known" codes
  if (results->decode_type != UNKNOWN) {
    // All protocols have data
    printf("unsigned int  data = 0x");
    printf("%lx", results->value);
    printf(";\n");
  }
}