#ifndef SENSORHW481_H
#define SENSORHW481_H

#include "DHT11.h"

/**
* @class sensorTemp
* @brief Clase para manejar el sensor de temperatura y humedad de dispositivos con chip DHT11.
*/

class sensorTemp : public DHT11 {
    public:
        /**
     * @brief Constructor de la clase sensorTemp
     * @param unsigned int pin: Inicializa el sensor DHT11 en el pin especificado.
     */

        sensorTemp(int = -1);

        // float leerHumedad();
        int leerTemperatura();
        void setPin(unsigned int);
        // void imprimirTemperatura();
        // void imprimirHum();

    private:
        bool verificarPin();

};

#endif
