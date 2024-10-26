#include "Buzzer.h"

Buzzer::Buzzer(int buzzPin, int potPin) {
    this->buzzPin = buzzPin;
    this->potPin = potPin;
}

void Buzzer::setup() {
    pinMode(buzzPin, OUTPUT);
    Serial.begin(9600);
    pinMode(potPin, INPUT);
}

void Buzzer::update() {
    potVal = analogRead(potPin);
    buzzDelay = (9940.0 / 1023.0) * potVal + 60;

    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(buzzDelay);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(buzzDelay);

    Serial.println(potVal);
}
