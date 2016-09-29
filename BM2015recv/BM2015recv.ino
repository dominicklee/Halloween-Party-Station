// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

int done = 0;
unsigned long time;

void yNodd(int bpm)
{
  bpm = (float)60000 / bpm;
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, HIGH);

    randLight();
    delay(bpm - 150);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, HIGH);
    delay(150);
}

void randLight()
{
   int rand1 = random(6) + 1 + 2;  
   digitalWrite(rand1, LOW);  
   int rand2 = random(6) + 1 + 2; 
  digitalWrite(rand2, LOW);  
}
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(2, HIGH);
} 
 
 
void loop() 
{ 
   int bpm = 126;

   
   time = millis();
   if (time > 217000) {
     if (done == 0) {
       digitalWrite(2, LOW);
       delay(2000);
       digitalWrite(2, HIGH);
       delay(1000);
       done = 1;
     }
     else {
       
     }
   }
   else {
     yNodd(bpm);
   }
}




