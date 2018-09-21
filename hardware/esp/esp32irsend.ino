#include <esp32_rmt.h>
uint16_t addr = 8415, cmd = 4335;
ESP32_RMT rmt;

void setup() {
  Serial.begin(9600);
  //while(!Serial.available());
}

int x = 0;

void loop() {
  if (x>10000) {
    // Obs: está enviando invertido
    rmt.necSend(0xFB04, 0xF708); //0x20DF10EF 0xFB04F708
    x = 0;
    Serial.println("here");
  }
  x++;
}
