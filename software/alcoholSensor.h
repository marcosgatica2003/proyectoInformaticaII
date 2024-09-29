#ifndef ALCOHOLSENSOR_H
#define ALCOHOLSENSOR_H

class alcoholSensor {
    public:
        alcoholSensor(int pin);
        int leerNivelAlcohol ();

    private:
        int sensorPin;

};

#endif
