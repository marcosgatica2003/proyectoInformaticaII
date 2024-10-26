#include "Buzzer.h"

Buzzer buzzer(4, A4); // Instancia del buzzer, con el pin del buzzer y del potenciómetro

void setup() {
    buzzer.setup();
}

void loop() {
    buzzer.update();
}

