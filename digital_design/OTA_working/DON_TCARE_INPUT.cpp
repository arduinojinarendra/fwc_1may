

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
int Z=0,Y=0,X=0,W=0;
int D,C,B,A;
void sevenseg(int D,int C,int B,int A)
{ 
	digitalWrite(13,A);
	digitalWrite(14,B);
	digitalWrite(15,C);
	digitalWrite(16,D);
}
void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  
  //-------------------//
    
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  
  //-------------------//
  A=!W;
  B=(!Z&&!X&&W)||(X&&!W);
  C=(Y&&!X)||(!W&&Y)||(!Y&&X&&W);
  D=(Z&&!W)||(Y&&X&&W);

  sevenseg(D,C,B,A);
}




