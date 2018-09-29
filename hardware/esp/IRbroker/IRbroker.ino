//******************************************************************************
// OIC - Omnidirecional Infrared Center
// Embarcados Contest - Programa de Parcerias IoT - 2018
// @author: Diego, Roger, Maikel
//******************************************************************************

#include <esp32_rmt.h>
#include <IRremote.h>
#include <WiFi.h>
#include <PubSubClient.h>

ESP32_RMT IRsender;
IRrecv IRreceiver(4);

const char* ssid = "Cardoso-";
const char* password = "Cardoso3781";
const char* mqtt_server = "192.168.0.11";

WiFiClient EspWifiClient;
PubSubClient MqttClient(EspWifiClient);

void setupWifi();
void mqttReconnect();
void mqttCallback(char* topic, byte* message, unsigned int length);

void dumpInfo(decode_results *results);
void dumpCode(decode_results *results);

void setup() {
  Serial.begin(9600);
  // while(!Serial.available()); // temporary stuck

  setupWifi();
  MqttClient.setServer(mqtt_server, 1883);
  MqttClient.setCallback(mqttCallback);
  IRreceiver.enableIRIn();
}

void loop() {
  if (!MqttClient.connected()) {
    mqttReconnect();
  }
  MqttClient.loop();

  decode_results results;
  if (IRreceiver.decode(&results)) {
    dumpCode(&results);
    Serial.println("");
    IRreceiver.resume();

    String _tmp = String(results.value, HEX);
    char hexChars[20];
    _tmp.toCharArray(hexChars, 20);
    MqttClient.publish("calibrate", hexChars);
  }
}

void setupWifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void mqttCallback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic).startsWith("control")) {
    // IRsender.necSend(0x20DF10EF); // temporary fixed LG power button
    IRsender.necSend((int)strtol(messageTemp.c_str(), 0, 16));
  }
}

void mqttReconnect() {
  while (!MqttClient.connected()) {
    Serial.print("Attempting MQTT connection... ");
    if (MqttClient.connect("ESP32mqttClient")) {
      Serial.println("connected");
      // Subscribe
      MqttClient.subscribe("control/tv");
      MqttClient.subscribe("control/split");
      MqttClient.subscribe("control/light");
    } else {
      Serial.print("failed, rc=");
      Serial.print(MqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void  encoding(decode_results *results) {
  switch (results->decode_type) {
    default:
    case UNKNOWN:      Serial.print("UNKNOWN");       break;
    case NEC:          Serial.print("NEC");           break;
    case SONY:         Serial.print("SONY");          break;
    case RC5:          Serial.print("RC5");           break;
    case RC6:          Serial.print("RC6");           break;
    case DISH:         Serial.print("DISH");          break;
    case SHARP:        Serial.print("SHARP");         break;
    case JVC:          Serial.print("JVC");           break;
    case SANYO:        Serial.print("SANYO");         break;
    case MITSUBISHI:   Serial.print("MITSUBISHI");    break;
    case SAMSUNG:      Serial.print("SAMSUNG");       break;
    case LG:           Serial.print("LG");            break;
    case WHYNTER:      Serial.print("WHYNTER");       break;
    case AIWA_RC_T501: Serial.print("AIWA_RC_T501");  break;
    case PANASONIC:    Serial.print("PANASONIC");     break;
    case DENON:        Serial.print("Denon");         break;
  }
}

void dumpInfo(decode_results *results) {
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");
  Serial.print("Code      : ");
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

void dumpCode(decode_results *results) {
  Serial.print("unsigned int  ");
  Serial.print("rawData[");
  Serial.print(results->rawlen - 1, DEC);
  Serial.print("] = {");

  for (int i = 1; i < results->rawlen; i++) {
    Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    if (i < results->rawlen-1) Serial.print(",");
    if (!(i & 1))  Serial.print(" ");
  }

  Serial.print("};");
  Serial.print("  // ");
  encoding(results);
  Serial.print(" ");
  Serial.print(results->value, HEX);
  Serial.println("");

  if (results->decode_type != UNKNOWN) {
    Serial.print("unsigned int  data = 0x");
    Serial.print(results->value, HEX);
    Serial.println(";");
  }
}
