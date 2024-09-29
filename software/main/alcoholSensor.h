#ifndef ALCOHOLSENSOR_H
#define ALCOHOLSENSOR_H

class alcoholSensor {
    public:
        alcoholSensor(int pin, unsigned int bits);
        int leerNivelAlcohol ();
        int iniciarPrueba(const unsigned int pinPrueba);

    private:
        int sensorPin;
        unsigned int adcMax;
};

#endif
