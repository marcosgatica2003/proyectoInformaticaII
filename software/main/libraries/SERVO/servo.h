#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include "Servo.h"

/**
 * @class puertaServo
 * @brief Clase para controlar una puerta usando un servomotor.
 * Emplea métodos de la biblioteca Servo.h para rotar el servo de 0 a pi/2.
 */

class puertaServo {
    public:

        /**
         * @brief Constructor de la clase puertaServo.
         * @param pin: Establece el pin PWM digital para hacer rotar el servomotor.
         */

        puertaServo(unsigned int pin);

        /**
         * @brief void inicializar();
         * Establece el pin pasado dado como parámetro durante la inicialización del objeto, a la clase dentro de Servo.h.
         */

        void inicializar();

        /**
         * @brief void abrir();
         * Hace rota pi/2 el servomotor.
         */

        void abrir();

        /**
         * @brief void cerrar();
         */

        void cerrar();

    private:
        int _pin; ///< Miembro privado que contiene el pin PWM para el servomotor.
        Servo _servo; ///< Objeto miembro privado de la clase Servo dentro de Servo.h para controlar el mismo.
};

#endif
