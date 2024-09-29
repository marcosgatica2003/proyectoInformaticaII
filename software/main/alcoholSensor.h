#ifndef ALCOHOLSENSOR_H
#define ALCOHOLSENSOR_H

class alcoholSensor {
    public:
        alcoholSensor(int pin, unsigned int bits);
        int leerNivelAlcohol ();

    private:
        int sensorPin;
        unsigned int adcMax;
};

#endif
