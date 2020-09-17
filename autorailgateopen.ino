int mpin1;
int mpin2;
int mdelay;

void setup() {

  pinMode(13,OUTPUT); // Green LED pin
  pinMode(7,OUTPUT); //Buzzer & Red Light pin

  //IR sensors pins
  pinMode(8,INPUT);
  pinMode(9,INPUT);

  //Initially turning on the  Green LED.
  digitalWrite(13,HIGH);

  //motor pins
  mpin1 = 2;
  mpin2 = 4;

  pinMode(mpin1, OUTPUT);
  pinMode(mpin2, OUTPUT);

  mdelay = 200;

  Serial.begin(9600);
}

void loop() 
{
  
  //IF IR sensors sense the train, then it will give LOW signal.
  if(digitalRead(8)==LOW){
    
    //Turning off the GREEN LED
    digitalWrite(7, HIGH);

    //Turning on the Buzzer & RED LED
    digitalWrite(13, LOW);

    Serial.println("buzzer on");
    
    
    //Shutting down the gate
    digitalWrite(mpin1, HIGH);
    digitalWrite(mpin2, LOW);
    
    delay(mdelay);
    //the gate has been shut down, stop motor
    digitalWrite(mpin1, LOW);

    //wait for the other IR on the opposite side to give signal
    while(digitalRead(9)==HIGH){
    }

    
    digitalWrite(7, LOW);
    digitalWrite(13, HIGH);
    
    Serial.println("buzzer off");
    
    delay(500);
    
    //The train has passed, open the gate, rotate the motor opposite direction
    digitalWrite(mpin2, HIGH);
    delay(mdelay);

    //the gate has been opened, stop the motor
    digitalWrite(mpin1, HIGH);
    delay(500);

  } else if(digitalRead(9)== LOW){
    digitalWrite(7, HIGH);
    digitalWrite(13, LOW);
    Serial.println("Buzzer on");

    digitalWrite(mpin1, HIGH);
    digitalWrite(mpin2, LOW);

    delay(mdelay);

    digitalWrite(mpin2, HIGH);
        
    while(digitalRead(8)==HIGH){
    }

    digitalWrite(7, LOW);
    digitalWrite(13, HIGH);

    Serial.println("Buzzer off");

    delay(500);

    digitalWrite(mpin1, LOW);

    delay(mdelay);

    digitalWrite(mpin1, HIGH);
    
    delay(500);
  } 
     
}
