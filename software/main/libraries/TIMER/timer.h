/**
 * @file timer.h
 * @brief Declaración de la clase timer para manejar dos fases de un temporizador, con antirrebote y un reset.
 */

#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

/**
 * @class timer
 * @brief Clase para gestionar un temporizador con dos salidas, cada una es activada en intervalos distintos, con la funcionalidad de antirrebote en los pines de ingreso y reset.
 */
class timer {
    public:
/**
 * @brief Constructor de la clase timer.
 * @param pIngreso: Pin de ingreso para activar el temporizador.
 * @param pReset: Pin para resetear el temporizador.
 * @param p1: Pin de la primera salida, activado después de tiempoUno.
 * @param p2: Pin de la segunda salida, activado después de tiempoDos.
 * @param t1: Tiempo (en milisegundos) después para activar la primera salida.
 * @param t2: Tiempo (en milisegundos) después para activar la segunda salida.
 * @param rebote: Tiempo de antirrebote para los pines de ingreso y reset.
 */

       timer(int pIngreso, int pReset, int p1, int p2, unsigned long t1, unsigned long t2, unsigned long rebote);

/**
 * @brief void iniciar(): configura los pines del objeto de clase timer como entradas y salidas.
 */

       void iniciar();
/**
 * @brief void actualizar(): Actualiza el estado del temporizador y controla las salidas según los tiempos establecidos.
 * Verifica el estado de los pines de ingreso y reset, aplicando antirrebote.
 */
       void actualizar();

    private:
        const unsigned long tiempoUno; /**< Tiempo de activación de la primera salida en milisegundos. */
        const unsigned long tiempoDos; /**< Tiempo de activación de la segunda salida en milisegundos. */
        unsigned long tiempoAntirrebote; /**< Tiempo para antirrebote del pin de ingreso y para el pin de reset. */
        unsigned long ultimoTiempoIngreso; /**< Último tiempo registrado para el pin de ingreso, usado en antirrebote. */
        unsigned long ultimoTiempoReset; /**< Último tiempo registrado para el pin de reset, usado en antirrebote. */
        unsigned long cont1; /**< Variable para almacenar el tiempo de inicio de la cuenta regresiva. */
        int pinIngreso; /**< Pin de ingreso para iniciar el temporizador. */
        int pinSalidaUno; /**< Pin de salida uno tras cumplir el tiempoUno. */
        int pinSalidaDos; /**< Pin de salida dos tras cumplir el tiempoDos. */
        int pinReset; /**< Pin de reset del temporizador activo. */
        bool contON; /**< Estado del temporizador. */

/**
 * @brief bool antirrebote(int, unsigned long&): Verifica el estado de un pin aplicando antirrebote.
 * @param int: El pin a verificar.
 * @param unsigned long&: Referencia al último tiempo registrado para el pin (antirrebote).
 * @return true si el pin está activado después del tiempo de antirrebote, false en caso contrario.
 */
        bool antirrebote(int, unsigned long&);
};

#endif

