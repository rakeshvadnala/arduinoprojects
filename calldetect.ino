#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
   pinMode(8,OUTPUT);
   lcd.print("Call Detector");
}
void loop() {
  if(analogRead(A0)>500)
  {
    lcd.clear();
    lcd.print("Call Detect");
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(2000);
   lcd.clear();
   lcd.print("Call Detect End");
  }
}

