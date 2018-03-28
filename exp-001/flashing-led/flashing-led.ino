/**
 * Set variable digital pin to 10 which will 
 * be used for the board later.
 */
int ledPin = 10;


/**
 * This sets up the mode for the pin stated at the 
 * beginning of the code.
 */
void setup()
{
  pinMode(ledPin, OUTPUT);
}


/**
 * Simple loop for making a LED flash on and off 
 * repeatedly using the digital PWM pin 10.
 */
void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
