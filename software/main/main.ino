/**
* @file main.ino
* @brief Programa principal para controlar el acceso a una cámara frigorífica usando RFID.
* 
* Este archivo utiliza la clase accesoRFID para leer tarjetas RFID y determinar si una tarjeta tiene acceso autorizado.
*/

#include <accesoRFID.h>

#define SS_PIN 10 ///< Pin SS para el módulo RFID
#define RST_PIN 9 ///< Pin RST para el módulo RFID

accesoRFID accesoCamFrig(SS_PIN, RST_PIN, "B0 AC 7E 7A"); ///< Instancia del acceso RFID para la cámara frigorífica.


/**
* @brief void setup()
* 
* Inicializa la comunicación serial y el módulo RFID.
*/

void setup() {
  Serial.begin(9600);
  accesoCamFrig.start();
}

/**
* @brief void loop()
* 
* if(accesoCamFrig.autorizar()): Llama a la función autorizar() de la clase accesoRFID para verificar si la tarjeta leída tiene acceso.
*/

void loop() {
  if(accesoCamFrig.autorizar()) {
    //Acceso autorizado
  } else {
    //Acceso denegado
  }
}