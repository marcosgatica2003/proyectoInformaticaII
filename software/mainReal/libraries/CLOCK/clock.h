#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

/**
 * @class reloj
 * @brief Clase que gestiona un reloj en formato HORAS-MINUTOS-SEGUNDOS.
 * Controla el avance del tiempo en un punto dado durante la creación de objetos derivados de la misma.
 */

class reloj {
    public:

        /**
         * @brief Constructor de la clase reloj
         * @param hora: inicio de hora en formato 0-24
         * @param minuto: inicio de minutos.
         * @param segundo: inicio de segundos.
         */

        reloj(unsigned int hora, unsigned int minuto, unsigned int segundo);

        /**
         * @brief void actualizar();
         * Continua avanzando el tiempo.
         */

        void actualizar();

        /**
         * @brief unsigned int getHoras() const;
         * Función constante que devuelve la hora.
         */

        unsigned int getHoras() const;

        /**
         * @brief unsigned int getMinutos() const;
         * Función constante que devuelve los minutos.
         */

        unsigned int getMinutos() const;

        /**
         * @brief unsigned int getSegundos() const;
         * Función constante que devuelve los segundos.
         */

        unsigned int getSegundos() const;

    private:

        unsigned int _horas; ///< Miembro privado que almacena la hora de inicio.
        unsigned int _minutos; ///< Miembro privado que almacena los minutos de inicio.
        unsigned int _segundos; ///< Miembro privado que almacena los segundos de inicio.
        unsigned long _ultimaActualizacion; ///< Miembro privado que almacena el tiempo para el avance del mismo y las variables miembro privados anteriores.

};

#endif
