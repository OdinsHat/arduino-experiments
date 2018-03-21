/**
 * Variable resistor port (pot) set to 0
 */
int potpin = 0;

/**
 * Set variable digital pin to 10 which will 
 * be used for the board later.
 */
int ledpin = 11;

/**
 * Temporary variable showing analog read value from potentiometer
 */
int val = 0;

/**
 * The serial baud rate used for viewing the serial output 
 * of the circuit.
 */
int baudRate = 9600;

/**
 * Set PWM pin 11 to output which is connected to the 
 * anode of the LED.
 * 
 * baudRate is set using the above integer value.
 * 
 * Analog ports are automatically set up as INPUT
 */
void setup()
{
    pinMode(ledpin, OUTPUT);
    Serial.begin(baudRate);
}

/**
 * Taking analog reading from POT use it to analogWrite 
 * that value to the LED (0-255). There's a 10ms delay 
 * before the change in LED output.
 * 
 * Effectively a convoluted dimming switch that uses the PWM pins of the Mega 
 * 2860 board to write analog values out at varying levels.
 * 
 * For informatio on PWN pins on Arduino boards see @link https://www.arduino.cc/en/Tutorial/PWM
 */
void loop()
{
    val = analogRead(potpin);
    Serial.println(val);
    analogWrite(ledpin, val/4);
    delay(10);
}
