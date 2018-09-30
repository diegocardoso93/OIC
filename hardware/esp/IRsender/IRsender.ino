//******************************************************************************
// OIC - Omnidirecional Infrared Center
// Embarcados Contest - Programa de Parcerias IoT - 2018
// @author: Diego, Roger, Maikel
//******************************************************************************

#include <esp32_rmt.h>
#include <WiFi.h>
#include <PubSubClient.h>

ESP32_RMT IRsender;

const char* ssid = "Cardoso-";
const char* password = "Cardoso3781";
const char* mqtt_server = "192.168.0.11";

WiFiClient EspWifiClient;
PubSubClient MqttClient(EspWifiClient);

void setupWifi();
void mqttReconnect();
void mqttCallback(char* topic, byte* message, unsigned int length);

void setup() {
  Serial.begin(9600);
  // while(!Serial.available()); // temporary stuck

  setupWifi();
  MqttClient.setServer(mqtt_server, 1883);
  MqttClient.setCallback(mqttCallback);
}

void loop() {
  if (!MqttClient.connected()) {
    mqttReconnect();
  }
  MqttClient.loop();

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
      MqttClient.subscribe("control/receptor-tv");
    } else {
      Serial.print("failed, rc=");
      Serial.print(MqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
