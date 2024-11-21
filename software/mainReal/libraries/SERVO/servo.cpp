#include "servo.h"

puertaServo::puertaServo(unsigned int pin): _pin(pin) {}

void puertaServo::inicializar() { _servo.attach(_pin); cerrar(); }

void puertaServo::abrir() { _servo.write((int)90); }

void puertaServo::cerrar() { _servo.write((int)0); }

