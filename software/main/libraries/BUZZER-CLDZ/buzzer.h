#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

/**
 * @class buzzer
 * @brief Clase para controlar el buzzer pasivo
 * Esta clase divide los tiempos en lo que el buzzer pasivo suena, siendo uno breve y otro intenso.
 */

class buzzer {
public:

    /**
     * @brief Constructor de la clase buzzer
     * @param buzzerPin: el pin que conecta el Vcc del buzzer.
     * @param potenciometroPin: pin análogo para variar la intensidad (volumen) para buzzer's activos.
     */

    buzzer(int buzzerPin, int potenciometroPin);
    
    /**
     * @brief void update();
     * Controla de manera no bloqueante los tiempos para hacer sonar el buzzer.
     */

    void update();

    /**
     * @brief: void emitirSonidoBreve();
     * Hace sonar el buzzer con un tiempo breve.
     */

    void emitirSonidoBreve();

    /**
     * @brief emitirSonidoIntenso();
     * Hace sonar el buzzer con un tiempo más intenso.
     */

    void emitirSonidoIntenso();

private:
    int buzzerPin; ///< Instancia que almacena el pin Vcc del buzzer.
    int potenciometroPin; ///< Instancia que almacena el pin del potenciometro.
    int potenciometroVal; ///< Instancia que almacena el valor del potenciometro.
    unsigned long tiempoAnteriorBreve; ///< Tiempo no bloqueante para sonar brevemente.
    unsigned long tiempoAnteriorIntenso; ///< Tiempo no bloqueante para sonar el buzzer de forma intensa.
    bool sonandoBreve; ///< Estado del buzzer si suena de forma breve.
    bool sonandoIntenso; ///< Estado del buzzer si suena de forma intensa.
};

#endif
