#include "DHT11.h"
#include "setPin.h"

/**
 * @file setPin.cpp
 * @brief Función amiga setPinDHT11
 * @param DHT11& sensor: recibe una referencia al objeto de la clase DHT11 al cual se le cambiará el pin de conexión correspondiente al sensor de temperatura.
 * @param int pin: es el nuevo pin para la entrada de datos del sensor de temperatura.
 * @details La función comprueba si el pin es válido, luego "desactiva" el pin anterior para inicializar el nuevo.
*/

void setPinDHT11(DHT11& sensor, int pin) {

    if (pin > 0) {

     /**
     * @details Bloque if-else
     * Controla si el pin ingresado es uno físicamente válido. Imprime por puerto serie UART un mensaje de error en caso de no serlo.
     */

        /**
         * @brief pinMode(sensor._pin, INPUT)
         * "Desactiva" el pin anterior.
        */

        pinMode(sensor._pin, INPUT);

        /**       
         * @brief sensor._pin = pin
         * Actualiza el pin.
        */

        sensor._pin = pin;

        /**
         * @brief pinMode(pin, OUTPUT) y digitalWrite(pin, HIGH)
         * Inicializa el nuevo pin como lo hace internamente la clase DHT11
        */

        pinMode(pin, OUTPUT);

        digitalWrite(pin, HIGH);

        /**
         * @brief delay(250)
         * Tiempo de espera a que el sensor se estabilice.
        */

        delay(250);

    } else {
        Serial.print("Pin del DHT11 inválido.");
    }

}
