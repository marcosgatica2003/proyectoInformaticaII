#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class buzzer {
public:
    buzzer(int buzzerPin, int potenciometroPin);
    // void setup();
    void update();
    void emitirSonidoSuave();
    void emitirSonidoFuerte();

private:
    int buzzerPin;
    int potenciometroPin;
    int potenciometroVal;
    unsigned long tiempoAnteriorSuave;
    unsigned long tiempoAnteriorFuerte;
    bool sonandoSuave;
    bool sonandoFuerte;
};

#endif
