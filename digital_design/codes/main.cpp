#include <Arduino.h>

int  w,x,y,z ;
int D,C,B,A ;
void disp_7447(int D,int C,int B,int A) {
  digitalWrite(2,A);
  digitalWrite(3,B);
  digitalWrite(4,C);
  digitalWrite(5,D);
}
void setup(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(13,OUTPUT);
}
void loop() {
digitalWrite(13,HIGH);
delay(1000);
w = digitalRead(8);
x = digitalRead(7);
y =digitalRead(9);
z = digitalRead(10);
digitalWrite(13,LOW);
A = (!w);
B = (w&&!x&&!z)||(!w&&x);
C = (!x&&y)||(!w&&y)||(w&&x&&!y);
D = (!w&&z)||(w&&x&&y);
disp_7447(D,C,B,A);
delay(1000);
}

