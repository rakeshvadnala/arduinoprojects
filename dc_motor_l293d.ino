const int potPin = A0;
const int fwdbuttonPin = 13;
const int bckbuttonPin = 12;
const int pin1 = 11;
const int pin2 = 10;

int potValue = 0;
int motorValue = 0;
int fwdbuttonState = 0;
int bckbuttonState = 0;

void setup() 
{
 
 pinMode(fwdbuttonPin, INPUT_PULLUP);
 pinMode(bckbuttonPin, INPUT_PULLUP);
 pinMode (pin1, OUTPUT);
 pinMode (pin2, OUTPUT);

}

void loop() 
{
 
 potValue = analogRead(potPin);  
 motorValue = map(potValue, 0, 1023, 0, 255);
 fwdbuttonState = digitalRead(fwdbuttonPin);
 bckbuttonState = digitalRead(bckbuttonPin);
 
 if (fwdbuttonState == LOW) 
  {
  
   analogWrite(pin1, motorValue);
   digitalWrite (pin2, LOW);  
    
  }
 
 else if (bckbuttonState == LOW)  
  {
   
   analogWrite(pin2, motorValue);
   digitalWrite (pin1, LOW);
     
  }
  
  else 
  {
   
   digitalWrite (pin1, LOW);
   digitalWrite (pin2, LOW);  

  }
  
}
