#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String readString;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="button_1"){
      lcd.clear();
      lcd.print("Mert Arduino");
    }

    if (readString =="button_2"){
      lcd.clear();
      lcd.print("Hello World");
    }

    if (readString =="button_3"){
      lcd.clear();
      lcd.print("Please Subscribe");
    }

    if (readString =="button_4"){
      lcd.clear();
      lcd.print("Youtube Channel");
    }
    readString="";
  }
}
