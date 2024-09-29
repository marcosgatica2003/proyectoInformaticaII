#include "alcoholSensor.h"
#include <Arduino.h>
alcoholSensor::alcoholSensor(int pin, unsigned int bits) {
    sensorPin = pin;
    pinMode(sensorPin, INPUT);
    adcMax = (1 << bits) -1;
}

int alcoholSensor::leerNivelAlcohol() {
    int valor = analogRead(sensorPin);
    return map(valor, 0, adcMax, 0, 100);
}

int alcoholSensor::iniciarPrueba (const unsigned int pinPrueba) {
    int estado = 0;
    if (digitalRead(pinPrueba) == HIGH) {
      ++estado;
    }
    return estado;
}