/*
V4 Gauntlet Code (Last updated 7/6/15)
 Code written by Dominick Lee.
 Distributed under the GPL v2 License for free use.
 For more information, please visit:  http://lifebeam.net/SHIV
 */


//Wireless Transceiver Declarations

/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[3];  // 3 element array holding Joystick readings

//END of Wireless Transceiver Declarations

//MPU6050 stuff
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"


// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define LED_PIN 13
bool blinkState = false;

int axf, ayf, azf;
int gxf, gyf, gzf;

int axFinal, ayFinal, azFinal;
int gxFinal, gyFinal, gzFinal;

int lastGX, lastGY, lastGZ;

boolean activated = false;

void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  //Start up the Wireless Transceiver
  radio.begin();
  radio.openWritingPipe(pipe);

  // initialize serial communication
  // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
  // it's really up to you depending on your project)
  Serial.begin(38400);

  // initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");


  delay(500);
  // read raw accel/gyro measurements from device
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  axf = -1 * (ax);
  ayf = -1 * (ay);
  azf = -1 * (az);
  gxf = -1 * (gx);
  gyf = -1 * (gy);
  gzf = -1 * (gz);
  

}

void loop() {
  // read raw accel/gyro measurements from device
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  axFinal = map(constrain((ay + ayf), -14000, 14000), -14000, 14000, -500, 500);
  ayFinal = map(constrain((az + azf), -14000, 14000), -14000, 14000, -500, 500);
  gxFinal = map(constrain((gy + gyf), -14000, 14000), -14000, 14000, -500, 500);
  gyFinal = map(constrain((gz + gzf), -14000, 14000), -14000, 14000, -500, 500);  

  /*
  Serial.print("X: ");
  Serial.print(axFinal);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.print(ayFinal);
  Serial.print("\t");
  Serial.print("X: ");
  Serial.print(gxFinal);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.println(gyFinal);
  */

  joystick[0] = axFinal;
  joystick[1] = ayFinal;
  joystick[2] = 0;
  
  radio.write( joystick, sizeof(joystick) );
  //delay(25);
}
