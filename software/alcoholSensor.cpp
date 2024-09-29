#include "alcoholSensor.h"
#include <Arduino/libraries/ArduinoBLE/extras/test/include/Arduino.h>

alcoholSensor::alcoholSensor(int pin) {
    sensorPin = pin;
    pinMode(sensorPin, INPUT);
    
}

int alcoholSensor::leerNivelAlcohol() {
    int valor = analogRead(sensorPin);
    return map(valor, 0, 1023, 0, 100);
}
