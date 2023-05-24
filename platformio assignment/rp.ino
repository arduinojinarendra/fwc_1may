#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11,8,7,6,5);  // Initialize the LCD object with the appropriate pins

byte memory[65536];  // Array to simulate memory

void setup() {
pinMode(9,OUTPUT);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  // Initialize memory with values
  memory[0x2001] = 0x98;  // Memory location 2001H with value 98H
  memory[0x2002] = 0xB1;  // Memory location 2002H with value B1H

  lcd.print("Calculating...");
}

void loop() {
analogWrite(9,100);
  // Perform the program execution
  int HL = 0x2001;       // Initialize HL register pair to point to memory location 2001H
  int A = 0x21;          // Initialize accumulator with value 21H

  HL++;                 // Increment HL to point to memory location 2002H
  A += memory[HL];      // Add the value at memory location 2002H to accumulator
  HL++;                 // Increment HL to point to memory location 2003H
  memory[HL] = A;       // Store the value in the accumulator to memory location 2003H

  // Display the value in memory location 2003H on the LCD screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Result:");
  lcd.setCursor(0, 1);
  lcd.print(memory[0x2003]);

  
  while (1) {
    
  }
}
