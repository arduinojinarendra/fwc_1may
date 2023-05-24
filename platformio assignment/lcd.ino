#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11,8,7,6,5);  // (rs, enable,4,5,6,7)

byte memory[65536];  // 64kb 64*1024=65536 8085 is 8bit microprocessor 

void setup() {
pinMode(9,OUTPUT);  //pwm generation pin(vo)
  lcd.begin(16, 2);  // LCD with 16 columns and 2 rows
 
  memory[0x2001] = 0x98;  //give Memory location 2001H with value 98H
  memory[0x2002] = 0xB1;  // give Memory location 2002H with value B1H
  lcd.print("Calculating...");
}




void loop() {
analogWrite(9,100);//pwm control
  
  int HL = 0x2001;       // HL register pair to point to memory location 2001H
  int A = 0x21;          // accumulator with value 21H

  HL++;                 // Increment HL becomes 2002H=B1H
  A += memory[HL];      // [a]+dataHL pair 21H+B1H
  HL++;                 // 2002H+1H = 2003H
  memory[HL] = A;       // 2003H=D2H

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Result:");
  lcd.setCursor(0, 1);
  lcd.print(memory[0x2003]);

  
  while (1) {
    
  }
}


