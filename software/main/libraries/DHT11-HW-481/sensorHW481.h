#ifndef SENSORHW481_H
#define SENSORHW481_H

#include "Bonezegei_DHT11.h"

/**
* @class sensorTemp
* @brief Clase para manejar el sensor de temperatura y humedad de dispositivos con chip DHT11.
*/


class sensorTemp {
    public:

        /**
        *@brief Constructor de la clase sensorTemp
        *
        *@param unsigned int pin: Inicializa la clase con el pin -1 cuando los objetos derivados de esta clase no reciben argumentos.
        */

        sensorTemp(unsigned int pin = -1);

        /**
        *@brief float leerHumedad()
        *
        * Consulta al sensor la humedad que detecta, usando la biblioteca Bonezegei_DHT11.
        *
        *@brief float leerTemperatura()
        *
        * Consulta al sensor la temperatura que detecta, usando la biblioteca Bonezegei_DHT11.
        *
        *@brief bool verificarLectura()
        *
        * Revisa que el sensor esté recibiendo lecturas correctas y no fluctuaciones o falsas medidas.
        *
        * @brief setPin(unsigned int)
        *
        * El método permite establecer un valor en el dato miembro privado pin.
        *
        *@brief void imprimirTemp() & imprimirHum()
        *
        * Manda por puerto serie UART las lecturas de temperatura y humedad respectivamente.
        *
        *
        */


        float leerHumedad();
        float leerTemperatura();
        bool verificarLectura();
        void setPin(unsigned int);
        void imprimirTemp();
        void imprimirHum();
    private:
        unsigned int pin; ///< Instancia del sensor DHT11
        Bonezegei_DHT11 dht11; ///< Objeto de la clase Bonezegei_DHT11 para controlar los dispositivos con este integrado.
        bool verificarPin(); ///< Función privada para verificar que exista un pin válido (pin> 0 != -1).
};

#endif

