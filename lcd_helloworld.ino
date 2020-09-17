#include <LiquidCrystal.h>//Don't forget to enter this library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {


lcd.begin(16, 2);


lcd.print("HELLO WORLD!");
delay(2000);
lcd.clear();
}

void loop() {

// set the cursor to column 0, line 1

// (note: line 1 is the second row, since counting begins with 0):

lcd.setCursor(5, 1);
lcd.print("BOY");
lcd.clear();

lcd.setCursor(4,0);
lcd.print("HELLO");


}
