#include <chrono>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <signal.h>

using namespace std;

void tmr_handler(int sig) {
  printf("us %d", sig);
}

int main () {
  signal(SIGALRM, &tmr_handler);
  ualarm(0, 1000);
}
