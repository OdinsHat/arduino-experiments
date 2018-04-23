#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Used the following DHT library: @link https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

/**
 * Setup for initialising the lcd, backlight snd serial console
 * and the DHT11 sensor.
 */
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop()
{
  // Create a delay of 2 seconds to give the sensor 
  // time to get the sensor values. 
  delay(2000);
  
  float h = dht.readHumidity();
  Serial.println(h);

  float t = dht.readTemperature();
  Serial.println(t);

  float f = dht.readTemperature(true);
  Serial.println(f);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  // Show temperature on second line
  lcd.setCursor(0, 0);
  lcd.print(t);
  lcd.setCursor(6, 0);
  lcd.print(" C");
  
  // Show humidity on first line
  lcd.setCursor(0, 1);
  lcd.print(h);
  lcd.setCursor(6, 1);
  lcd.print(" Humidity");
}