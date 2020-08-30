#include "env.h"
#include "weather.h"
#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>

int lastMinute = 0;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, UTC_OFFSET * 60 * 60);

void setup(){
  Serial.begin(115200);

  if (!initBM280()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  lastMinute = timeClient.getMinutes();
}

void loop() {
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds();
  String time = String(currentHour) + ":" + String(currentMinute);
  timeClient.update();

  if(lastMinute != currentMinute) {
    Serial.println(time);
    lastMinute = currentMinute;
  }

  if(currentSecond == 0 && currentMinute % 10 == 0) {
    Serial.println("Grab weather data, fully update screen");
  }

  delay( 1000 );
}