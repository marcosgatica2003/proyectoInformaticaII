/**
* @file main.ino
* @brief Programa principal para controlar el acceso a una cámara frigorífica usando RFID.
* 
* Este archivo utiliza la clase accesoRFID para leer tarjetas RFID y determinar si una tarjeta tiene acceso autorizado.
*/

#include "libraries/RFID-RC522/accesoRFID.h"
#include "libraries/RFID-RC522/accesoRFID.cpp"
#include "libraries/RFID-RC522/deprecated.h"
#include "libraries/RFID-RC522/MFRC522.cpp"
#include "libraries/RFID-RC522/MFRC522.h"
#include "libraries/RFID-RC522/MFRC522Extended.h"
#include "libraries/RFID-RC522/MFRC522Extended.cpp"
#include "libraries/RFID-RC522/require_cpp11.h"

#define SS_PIN 10 ///< Pin SS para el módulo RFID
#define RST_PIN 9 ///< Pin RST para el módulo RFID
#define TAM 2

String uidAccess[TAM] = {"87 9C 0A 4E", "79 C3 C3 A2"};

accesoRFID accesoCamFrig(SS_PIN, RST_PIN, uidAccess[0]); ///< Instancia del acceso RFID para la cámara frigorífica.

/**
* @brief bool verificarAcceso()
* 
* Función que devuelve true si alguna llave tiene permiso para entrar.
*/

bool verificarAcceso () {
  if(accesoCamFrig.autorizar()) {
    //Acceso autorizado
    Serial.println("Autorizado");

    return true;

  } else {
    //Acceso denegado
    Serial.println("Denegado");
  }
  
  return false;
}

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
  if(verificarAcceso()){
    //Abrir puerta
  }
}

