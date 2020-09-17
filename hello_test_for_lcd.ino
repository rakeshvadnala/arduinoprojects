#include <LiquidCrystal.h>
LiquidCrystal lcd(7 , 6, 5, 4, 3, 2);
void setup() {
  lcd.begin(16,2);
Serial.begin(9600);
}
void loop() {

  lcd.print("Hello LCD");
   lcd.print(" qqqqq");
 
  lcd.print("eeeee");
}


