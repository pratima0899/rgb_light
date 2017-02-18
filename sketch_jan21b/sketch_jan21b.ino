#include <Arduino.h>
#include <Wire.h>
#include <ArdusatSDK.h>


/*-----------------------------------------------------------------------------
 *  Setup Software Serial to allow for communication
 *----------------------------------------------------------------------------*/
ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);


/*-----------------------------------------------------------------------------
 *  Constant Definitions
 *----------------------------------------------------------------------------*/
Luminosity lum;
UVLight uv;


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  setup
 *  Description:  This function runs when the Arduino first turns on/resets.
 *                This is our chance to take care of all one-time configuration
 *                tasks to get the program ready to begin logging data.
 * =============================================================================
 */
void setup(void)
{
  serialConnection.begin(9600);

  lum.begin();
  

  /* We're ready to go! */
  serialConnection.println("");
}


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  loop
 *  Description:  After setup runs, this loop function runs until the Arduino 
 *                loses power or resets.
 * =============================================================================
 */
void loop(void)
{
  // Read Luminosity and UV
  lum.read();
  

  serialConnection.println(lum.toJSON("luminosity"));
 

  delay(100);
}
