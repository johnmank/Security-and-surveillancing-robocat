#include<SoftwareSerial.h>
SoftwareSerial mySerial(0,1);  //RX,TX
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
void setup()
{
 mySerial.begin(9600);

  //STARTING SERIAL COMMUNICATION
  
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}
void loop()
{
  
  char x;
  //CHECKING AVAILABLES BY BLUETOOTH MODULE
  
  if(Serial.available()>0)
  {
    x=mySerial.read();
     

    if(x=='F') //data sent from the  controller app  on your android phone
    {
      Serial.print("FO");
        
  //FORWARD
   
        pwm.setPWM(0, 0, angleToPulse(angle) );
        pwm.setPWM(1, 0, angleToPulse(angle) );
        pwm.setPWM(2, 0, angleToPulse(angle) );
        pwm.setPWM(3, 0, angleToPulse(angle) );
        pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(5, 0, angleToPulse(angle) );
        pwm.setPWM(6, 0, angleToPulse(angle) );
        pwm.setPWM(7, 0, angleToPulse(angle) );
    }
   
  
  
    
 
if(x=='B') //data sent from the  controller app  on your android phone
  {  

    Serial.print("BA");
    
  //BACKWARD
 
        pwm.setPWM(0, 0, angleToPulse(angle) );
        pwm.setPWM(1, 0, angleToPulse(angle) );
        pwm.setPWM(2, 0, angleToPulse(angle) );
        pwm.setPWM(3, 0, angleToPulse(angle) );
        delay(50);
        pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(5, 0, angleToPulse(angle) );
        pwm.setPWM(6, 0, angleToPulse(angle) );
        pwm.setPWM(7, 0, angleToPulse(angle) );
    
    
    
    
   }


 }
   
 
}
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
