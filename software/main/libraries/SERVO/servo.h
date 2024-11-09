#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include "Servo.h"
class puertaServo {
    public:
        puertaServo(unsigned int pin);
        void inicializar();
        void abrir();
        void cerrar();

    private:
        int _pin;
        Servo _servo;
};

#endif
