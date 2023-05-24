/* MQ-3 Alcohol Sensor Circuit with Arduino */
#include <Arduino.h>
#include <LiquidCrystal.h>

//const int AOUTPin=A0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTPin=A0;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=6;//the anode of the LED connects to digital pin D13 of the arduino
const int buzzPin = 7;
const int IN1 = 8;
const int IN2 = 9;
const int switchpin = 5;
int buttonState = 0; 
int alcohol = A0; 

int sm=1;
int limit=150;
int value;
LiquidCrystal lcd(12, 13, A2, A3, A4, A5);
void setup() 
  {
      Serial.begin(9600);//sets the baud rate
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
      Serial.begin(9600);
      //pinMode(alcohol, INPUT);
      pinMode(buzzPin,OUTPUT);
      pinMode(IN1,OUTPUT);
      pinMode(IN2,OUTPUT);
      pinMode(DOUTPin, INPUT);//sets the pin as an input to the arduino
      pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
      pinMode(switchpin, INPUT);
//      pinMode(AOUTPin, INPUT);// set pin INput
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,LOW); 
      lcd.clear();
      lcd.print("    Alcohol");
      lcd.setCursor(0,1);
      lcd.print("Detection System");
      delay(5000);
      lcd.begin(16, 2);
      lcd.print("Press Switch"); 
      
  }

void loop()
{
sm=1;
buttonState = digitalRead(switchpin);
if(buttonState==0)
  {
    lcd.clear(); 
    lcd.begin(16, 2);
    lcd.print("Please Wait...");
    
   buttonState = digitalRead(switchpin); 
   while(sm==1)
   { 
    //lcd.clear(); 
//      lcd.begin(16, 2);
 //   value= digitalRead(alcohol);
//    Serial.println(value);
   // lcd.print( value);//reads the analaog value from the alcohol sensor's AOUT pin
 //   delay(300);
    //limit= digitalRead(DOUTPin);//reads the digital value from the alcohol sensor's DOUT pin
    //Serial.print("Alcohol value: ");
    //Serial.println(value);//prints the alcohol value
    //Serial.print("Limit: ");
    //Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
    delay(1000);
    
    if (value == HIGH)
    {
      lcd.clear(); 
     //lcd.begin(16, 2);
      digitalWrite(ledPin, LOW);//if limit has been reached, LED turns on as status indicator
      lcd.print("  Alcohol Level");
      lcd.setCursor(0,1);
      lcd.print("   Under limit");
      delay(1000);
      lcd.clear(); 
      lcd.begin(16, 2);
      lcd.print("Engine Running  ");
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(buzzPin,LOW);
      digitalWrite(ledPin,LOW);
      delay(2000);       
    } 
    buttonState = digitalRead(switchpin); 
    if(buttonState==0)
    {
      lcd.begin(16, 2);
      lcd.print("Engine stop");
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,LOW);
      digitalWrite(buzzPin,LOW);
      digitalWrite(ledPin,LOW);
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Press Switch"); 
       sm=0;
       buttonState=1;
      delay(1000);   
    }
     value= digitalRead(alcohol);
      if (value == LOW)
          {
            lcd.begin(16, 2);
            lcd.print("Engine stop");
            digitalWrite(IN2,LOW);
            digitalWrite(IN1,LOW);
            digitalWrite(buzzPin,HIGH);
            digitalWrite(ledPin,HIGH);
            sm=0;
             buttonState=1;
            delay(2000);
           digitalWrite(buzzPin,LOW);
            digitalWrite(ledPin,LOW); 
          }
    }
    if (value == LOW)
    {
      lcd.clear(); 
      lcd.begin(16, 2);
      digitalWrite(ledPin, HIGH);//if threshold not reached, LED remains off
      lcd.print(" Alcohol Level");
      lcd.setCursor(0,1);
      lcd.print("   Over limit");
      digitalWrite(buzzPin,HIGH);
      digitalWrite(ledPin,HIGH);
      delay(3000);
      digitalWrite(buzzPin,LOW);
      digitalWrite(ledPin,LOW);
      lcd.begin(16, 2);
      lcd.print("Press Switch");
      delay(1000); 
    }
   }
 
  }
