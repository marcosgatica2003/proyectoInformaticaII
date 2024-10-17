/**
* @file conocerUID.ino
* @brief Imprime por puerto serie el UID de una tarjeta.
* Este programa permite leer la UID de las tarjetas para posteriormente implementarlas en el main.ino
*/


#include <accesoRFID.h>

#define SS_PIN 10
#define RST_PIN 9

accesoRFID leerUID(SS_PIN, RST_PIN, "");

void setup () {
  Serial.begin(9600);
  leerUID.start();
  Serial.println("Acerca la tarjeta para leer su UID: ");
}

void loop () {
  if (leerUID.detectarTarjeta()) {
    Serial.print("UID: ");
    leerUID.mostrarID();
    delay(2000);
  }
}