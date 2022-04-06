#include <Wire.h>
#include "Module_ADS1115.h"
Adafruit_ADS1015 ads1015;
unsigned long previousMillis = 0;
const long interval = 5000;
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV)");
  ads1015.begin();
  pinMode(13,OUTPUT);
}
void loop(void)
{
  unsigned long currentMillis = millis();
  int16_t adc0, adc1, adc2, adc3;
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    adc0 = ads1015.readADC_SingleEnded(0);
    adc1 = ads1015.readADC_SingleEnded(1);
    adc2 = ads1015.readADC_SingleEnded(2);
    adc3 = ads1015.readADC_SingleEnded(3);
    Serial.print("AIN0: "); Serial.println(adc0);
    Serial.print("AIN1: "); Serial.println(adc1);
    Serial.print("AIN2: "); Serial.println(adc2);
    Serial.print("AIN3: "); Serial.println(adc3);
    Serial.println(" ");
  }
  if(Serial.available()>0)
  {
    char ch = Serial.read();
    if(ch)
    {
      digitalWrite(13,HIGH);
    }
    if(ch == 'f')
    {
      digitalWrite(13,LOW);
    }   
  }
  
}

