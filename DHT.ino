#include <dht.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define dht_dpin 7
dht DHT;
#define pwm 6
byte degree[8] = 
              {
                0b00011,     0b00011,      0b00000,      0b00000,        0b00000,       0b00000,     0b00000,   0b00000
              };

void setup()
{
 lcd.begin(16, 2);
 lcd.createChar(1, degree);
 lcd.clear();
 lcd.print("   Fan Speed  ");
 lcd.setCursor(0,1);
 lcd.print("  Controlling ");
 delay(2000);
 analogWrite(pwm, 255);
 lcd.clear();
 lcd.print("Automatic Fan ");
 delay(2000);
}

void loop()
{
  DHT.read11(dht_dpin);
  int temp=DHT.temperature;
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);  
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(0,1);
  if(temp <26 )
    { 
      analogWrite(9,0);
      lcd.print("Fan OFF            ");
      delay(100);
    }
    
    else if(temp==26)
    {
      analogWrite(pwm, 51);
      lcd.print("Fan Speed: 20%   ");
      delay(100);
    }
    
     else if(temp==27)
    {
      analogWrite(pwm, 102);
      lcd.print("Fan Speed: 40%   ");
      delay(100);
    }
    
     else if(temp==28)
    {
      analogWrite(pwm, 153);
      lcd.print("Fan Speed: 60%   ");
      delay(100);
    }
    
    else if(temp==29)
    {
      analogWrite(pwm, 204);
      lcd.print("Fan Speed: 80%    ");
      delay(100);
    }
     else if(temp>29)
    {
      analogWrite(pwm, 255);
      lcd.print("Fan Speed: 100%   ");
      delay(100);
    } 
  delay(3000);
}
