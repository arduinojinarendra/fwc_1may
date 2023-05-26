

//Code by GVV Sharma
//April 29, 2022
//https://www.gnu.org/licenses/gpl-3.0.en.html
//
//Seven segment diplay OTA
//
//----------------------Skeleton Code--------------------//

//           LCD interfacing With ESP32     //


#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// set the LCD number of columns and rows
 
//    Can be client or even host   //
#ifndef STASSID
#define STASSID "realme 6i"  // Replace with your network credentials
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

//-------------------------------------------------------//
void sevenseg(int a,int b,int c,int d,int e,int f,int g);

void setup(){
  OTAsetup();
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(20,INPUT);
  pinMode(21,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  

  //-------------------//
  // Custom setup code //
  
  //-------------------//
    
}
int W,X,Y,Z,A,B,C,D;
void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  
  //-------------------//
  W=digitalRead(20);
  X=digitalRead(21);
  Y=digitalRead(22);
  Z=digitalRead(23);
  A=(!W&&!Z)||(!Y&&!X&&!W&&);
   B=(!Z&&!X&&W)||(!Z&&X&&!W);
 C=(!Z&&
  digitalWrite(13,A);
  digitalWrite(14,B);
  digitalWrite(15,C);
  digitalWrite(16,D);  
}




