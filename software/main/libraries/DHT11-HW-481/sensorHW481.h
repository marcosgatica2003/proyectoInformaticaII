#ifndef SENSORHW481_H
#define SENSORHW481_H

#include "DHT11.h"

class sensorTemp {
    public:
        sensorTemp();
        float leerHumedad();
        float leerTemperatura();
        bool verificarLectura();
        void imprimirTemp();
        void imprimirHum();
    private:
        unsigned int pin;
        DHT11 dht11;
};

#endif

