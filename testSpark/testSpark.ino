#include <TimedAction.h>

#include <Servo.h> 

Servo nodY, nodX;

//this initializes a TimedAction object that will change the state of an LED every second.
TimedAction sweepYAction = TimedAction(1000, sweepY);
//this initializes a TimedAction object that will change the state of an LED
//according to the serial buffer contents, every 50 milliseconds
TimedAction sweepXAction = TimedAction(50, sweepX);



void setup() {
  nodY.attach(9);
  nodX.attach(8);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sweepYAction.check(); //trigger every second
  sweepXAction.check(); //trigger every 50 millisecond
  //asciiTableAction.check(); //trigger every 10 second
}

void sweepX(int delaySpeed){
  for(int pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    nodX.write(pos);              // tell servo to go to position in variable 'pos'
    delay(delaySpeed);                       // waits 15ms for the servo to reach the position 
  } 
  for(int pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    nodX.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(delaySpeed);                       // waits 15ms for the servo to reach the position 
  }
}


void sweepY(int bmp){
  
  for(int pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    nodX.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
  for(int pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    nodX.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
}
