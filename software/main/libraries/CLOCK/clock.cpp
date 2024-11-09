#include "reloj.h"

reloj::reloj(unsigned int hora, unsigned int minuto, unsigned int segundo): _horas(hora), _minutos(minuto), _segundos(segundo, _ultimaActualizacion(millis())) {}

void reloj::actualizar() {
    unsigned long ahora = millis();
    unsigned long tiempoTrancurrido = ahora - _ultimaActualizacion;

    if (tiempoTrancurrido >= 1000) {
        _segundos += tiempoTrancurrido / 1000;
        _ultimaActualizacion = ahora;

        if (_segundos >= 60) {
            _segundos -= 60;
            _minutos++;
        }

        if (_minutos >= 60) {
            _minutos -= 60;
            _horas++;
        }

        if (_horas > = 24) {
            _horas = 0;
        }
    }
}

unsigned int reloj::getHoras() { return _horas; }
unsigned int reloj::getMinutos() { return _minutos; }
unsigned int reloj::getSegundos() { return _segundos; }

