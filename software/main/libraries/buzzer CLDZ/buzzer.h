#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
public:
    Buzzer(int buzzPin, int potPin);
    void setup();
    void update();

private:
    int buzzPin;
    int potPin;
    float buzzDelay;
    int potVal;
};

#endif
