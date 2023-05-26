#include<Arduino.h>

int D1,D2,x,y;
int p = 0,q = 0;

void setup()
{
	pinMode(2,INPUT);
	pinMode(3,OUTPUT);
	pinMode(13,OUTPUT);
}

void loop()
{
	digitalWrite(13,HIGH);
	delay(3000);

	x = digitalRead(2);
	digitalWrite(13,LOW);
	delay(2000);

	D1 = (!p&&q&&!x);
	D2 = (!q&&x)||(p&&x);
	y = (p&&!q&&x);

	if(y==1)
	{
		digitalWrite(3,HIGH);
	}
	p = D1;
	q = D2;
}

