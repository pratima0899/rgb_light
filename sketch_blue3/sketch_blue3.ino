/*
----------------------------------------------------------------------------
 *  Includes
 *-----------------------------------------------------------------------------*/
#include <Arduino.h>
#include <Wire.h>
#include <ArdusatSDK.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Luminosity lum;

/*-----------------------------------------------------------------------------
 *  Constant Definitions
 *-----------------------------------------------------------------------------*/
// Declare pins for RGB LED, all PWM pins
const uint8_t redPin = 3;
const uint8_t greenPin = 5;
const uint8_t bluePin = 6;

// Delay between changing the LED colors.  Change this value to experiment with different speeds
int LED_FLASH_DELAY= 300000;




  void setup(void)
{
  serialConnection.begin(9600);

  lum.begin();

  /* We're ready to go! */
  serialConnection.println("");

  /* We're ready to go! */
  

  // Set up pins for RGB LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void red()
{
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  //
}

void green()
{
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

//green
}
  
void pink()

{  analogWrite(redPin, 255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,255);
}
  //pink


void orange()
{
  analogWrite(redPin, 0);
  analogWrite(greenPin, 100);
  analogWrite(bluePin,25);

  //
}
void purple()
{
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

  //purple
} 

void yellow()
 {
  analogWrite(redPin, 10);
  analogWrite(greenPin,100);
  analogWrite(bluePin, 255);

  //yellow
 }

void blank()

{  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

} 
 


void blue()

{
analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

  //
}
 
void norgb(){
  analogWrite(redPin,255);
  analogWrite(bluePin,255);
  analogWrite(greenPin,255);
    
}


 
void loop(void)
{
 
 lum.read();

  serialConnection.println(lum.lux);
  

  delay(100);
  noInterrupts();
  if(lum.lux<13); 
  {
   analogWrite(redPin,255);
   analogWrite(bluePin,255);
   analogWrite(greenPin,255);
  delay(1000);
   }
  interrupts();
  red();
  delay(5000);
  blue();
  delay(5000);
  yellow();
  delay(5000);
  blank();
  delay(5000);
  pink();
  delay(5000);
  orange();
  delay(5000);
  green();
  delay(5000);
  purple();
  delay(5000);

  
   
   
    
  }
  
  




