#ifndef SENSORHW481_H
#define SENSORHW481_H

#include "Bonezegei_DHT11.h"

/**
* @class sensorTemp
* @brief Clase para manejar el sensor de temperatura y humedad de dispositivos con chip DHT11.
*/

class sensorTemp : public Bonezegei_DHT11 {
    public:
        /**
     * @brief Constructor de la clase sensorTemp
     * @param unsigned int pin: Inicializa el sensor DHT11 en el pin especificado.
     */

        sensorTemp(int8_t pin = -1);

        // float leerHumedad();
        float leerTemperatura();
        bool verificarLectura();
        void setPin(unsigned int);
        void imprimirTemperatura();
        // void imprimirHum();

    private:
        bool verificarPin();

};

#endif
