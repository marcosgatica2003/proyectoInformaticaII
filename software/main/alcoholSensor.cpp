#include "alcoholSensor.h"

alcoholSensor::alcoholSensor(int pin, unsigned int bits) {
    sensorPin = pin;
    pinMode(sensorPin, INPUT);
    adcMax = (1 << bits) -1;
}

int alcoholSensor::leerNivelAlcohol() {
    int valor = analogRead(sensorPin);
    return map(valor, 0, adcMax, 0, 100);
}
