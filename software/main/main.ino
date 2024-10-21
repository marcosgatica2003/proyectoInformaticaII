/**
* @file main.ino
* @brief Programa principal para controlar el acceso a una cámara frigorífica usando RFID.
* 
* @brief RFIDLibs.h 
* Este archivo de cabecera contiene lo necesario para usar el módulo RFID-RC522
*/

#include "libraries/RFID-RC522/RFIDLibs.h"
#include "libraries/DHT11-HW-481/DHT11Libs.h"

#define SS_PIN 10 ///< Pin SS para el módulo RFID
#define RST_PIN 9 ///< Pin RST para el módulo RFID
#define TAM 2

accesoRFID tarjetaRFID(SS_PIN, RST_PIN, "87 9C 0A 4E"); ///< Instancia del acceso RFID para la cámara frigorífica.
accesoRFID llaveroRFID(SS_PIN, RST_PIN, "79 C3 C3 A2"); ///< Instancia del acceso RFID para la cámara frigorífica.

sensorTemp sensor;

/**
* @brief bool verificarAcceso()
* 
* Función que devuelve true si alguna llave tiene permiso para entrar.
*/

bool verificarAcceso () {
  bool verif = false;

  if(tarjetaRFID.autorizar() || llaveroRFID.autorizar()) {

    Serial.println("Autorizado");
    verif = true;

  } else {
    Serial.println("Denegado");
  }
  
  return verif;
}

/**
* @brief void setup()
* 
* Inicializa la comunicación serial y el módulo RFID.
*/

void setup() {
  Serial.begin(9600);
  tarjetaRFID.start(); llaveroRFID.start();

}

void loop() {
  if(verificarAcceso()){
    //Abrir puerta
  }

   if (sensor.verificarLectura()) {
        Serial.print("Humedad: ");
        Serial.print(sensor.leerHumedad());
        Serial.println("%");

        Serial.print("Temperatura: ");
        Serial.print(sensor.leerTemperatura());
        Serial.println("°C");
    } else {
        Serial.println("Error en la lectura del sensor.");
    }

}

