#include<Arduino.h>
#include<Wire.h>
#include<ArdusatSDK.h>

Luminosity lum;
void setup()
{
  Serial.begin(9600);
  lum.begin();
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}
void loop(){
  lum.read();
  Serial.println(lum.lux);
  delay(1000);
   if(lum.lux<40)
   {
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
   }
  else 
  {
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,LOW);
  }
}

