//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "raja"  // Replace with your network credentials
#define STAPSK  "123456789"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}
///-------------------------------------------------------//
int a,b,y;


void setup(){
  OTAsetup();

  
    pinMode(15,INPUT);
    pinMode(17,INPUT);
    pinMode(19,OUTPUT);
    
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  a=digitalRead(15);
  b=digitalRead(17);
  y=!a|!b;
  digitalWrite(19,y);
  
  
}
