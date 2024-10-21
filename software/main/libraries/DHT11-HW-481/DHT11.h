/*
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : November 2023
*/

#ifndef DHT11_H
#define DHT11_H

#include <Arduino.h>

class DHT11 {
public:
  DHT11();
  DHT11(int8_t pin);
  char begin();
  char getData();
  float getTemperature();
  float getTemperature(bool fahrenheit);
  int getHumidity();

private:
  int8_t _pin;
  uint8_t data[6];
  unsigned long prevtime;

  int _humidity;
  float _temperatureDeg;
  float _temperatureFar;
};

#endif
