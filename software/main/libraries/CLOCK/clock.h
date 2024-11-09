#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

class reloj {
    public:
        reloj(unsigned int hora, unsigned int minuto, unsigned int segundo);

        void actualizar();
        unsigned int getHoras() const;
        unsigned int getMinutos() const;
        unsigned int getSegundos() const;

    private:

        unsigned int _horas;
        unsigned int _minutos;
        unsigned int _segundos;
        unsigned long _ultimaActualizacion;

};

#endif
