#include "sensorHW481.h"

sensorTemp::sensorTemp(int p): DHT11(p) {}

bool sensorTemp::verificarPin() {
    if(_pin == -1) {
        Serial.println("Pin inválido.");
        return false;
    }
    return true;
}

int sensorTemp::leerTemperatura() {
    if(verificarPin()){
        return DHT11::readTemperature();
    }
    return 0;
}

void sensorTemp::setPin (unsigned int p) {
    _pin = p;
}

