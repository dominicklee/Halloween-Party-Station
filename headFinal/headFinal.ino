// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo myservo2;

int pos = 0;    // variable to store the servo position 

void yNodd(int bpm)
{
  bpm = (float)6000 / bpm;
  myservo2.write(110);
  for(int i = 110; i > 100; i--)
  {
    int LED = map(i, 100, 110, 0, 100);
    analogWrite(6, LED);
    myservo2.write(i);
    delay(bpm);
  }
}
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
   int bpm = 126;
   myservo.write(85);
   yNodd(bpm);
   yNodd(bpm);
   myservo.write(95);
   yNodd(bpm);
   yNodd(bpm);
}
