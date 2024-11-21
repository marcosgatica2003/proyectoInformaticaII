#include "buzzer.h"

buzzer::buzzer(int buzzPin, int potPin) {
    this->buzzerPin = buzzPin; pinMode(buzzerPin, OUTPUT);
    this->potenciometroPin = potPin; pinMode(potenciometroPin, INPUT);
    sonandoBreve = false;
    sonandoIntenso = false;
}

// void buzzer::setup() {
//     pinMode(buzzerPin, OUTPUT);
//     pinMode(potPin, INPUT);
// }

void buzzer::update() {
    potenciometroVal = analogRead(potenciometroPin);
    Serial.println(potenciometroVal);
}

void buzzer::emitirSonidoBreve() {

    float delaySuave = (9940.0 / 1023.0) * potenciometroVal + 60;

    if(!sonandoBreve) {
        sonandoBreve = true;
        tiempoAnteriorBreve = millis();
    }

    if (sonandoBreve) {
        unsigned long tiempoActual = millis();
        if (tiempoActual - tiempoAnteriorBreve >= delaySuave) {
            digitalWrite(buzzerPin, !digitalRead(buzzerPin));
            tiempoAnteriorBreve = tiempoActual;
        }
    }
}

void buzzer::emitirSonidoIntenso() {

    float delayFuerte = (5000.0 / 1023.0) * potenciometroVal + 30;

    if(!sonandoIntenso) {
        sonandoIntenso = true;
        tiempoAnteriorIntenso = millis();
    }

    if (sonandoIntenso) {
        unsigned long tiempoActual = millis();
        if (tiempoActual - tiempoAnteriorIntenso >= delayFuerte) {
            digitalWrite(buzzerPin, !digitalRead(buzzerPin));
            tiempoAnteriorIntenso = tiempoActual;
        }
    }
}
