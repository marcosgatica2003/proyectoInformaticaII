#include "buzzer.h"

buzzer::buzzer(int buzzPin, int potPin) {
    this->buzzerPin = buzzPin; pinMode(buzzerPin, OUTPUT);
    this->potenciometroPin = potPin; pinMode(potenciometroPin, INPUT);
    sonandoSuave = false;
    sonandoFuerte = false;
}

// void buzzer::setup() {
//     pinMode(buzzerPin, OUTPUT);
//     pinMode(potPin, INPUT);
// }

void buzzer::update() {
    potenciometroVal = analogRead(potenciometroPin);
    Serial.println(potenciometroVal);
}

void buzzer::emitirSonidoSuave() {

    float delaySuave = (9940.0 / 1023.0) * potenciometroVal + 60;

    if(!sonandoSuave) {
        sonandoSuave = true;
        tiempoAnteriorSuave = millis();
    }

    if (sonandoSuave) {
        unsigned long tiempoActual = millis();
        if (tiempoActual - tiempoAnteriorSuave >= delaySuave) {
            digitalWrite(buzzerPin, !digitalRead(buzzerPin));
            tiempoAnteriorSuave = tiempoActual;
        }
    }
}

void buzzer::emitirSonidoFuerte() {

    float delayFuerte = (5000.0 / 1023.0) * potenciometroVal + 30;

    if(!sonandoFuerte) {
        sonandoFuerte = true;
        tiempoAnteriorFuerte = millis();
    }

    if (sonandoFuerte) {
        unsigned long tiempoActual = millis();
        if (tiempoActual - tiempoAnteriorFuerte >= delayFuerte) {
            digitalWrite(buzzerPin, !digitalRead(buzzerPin));
            tiempoAnteriorFuerte = tiempoActual;
        }
    }
}
