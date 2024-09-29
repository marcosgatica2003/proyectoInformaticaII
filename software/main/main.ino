#include "alcoholSensor.h"
//Pines
const int alcoholPin = A0;

//Niveles
const int limiteAlcohol = 50;
int nivelAlcoholAire = 0;

//Configuración
const unsigned int baud = 9600;
const unsigned int bitsADC = 10;

//Objetos
alcoholSensor sensorDeAlcohol(alcoholPin, bitsADC);


void setup() {
  Serial.begin(baud);
}

void loop() {
  nivelAlcoholAire = alcoholSensor.leerNivelAlcohol();
  Serial.println("Nivel de alcohol: " + String(nivelDeAlcoholAire))

  if (nivelAlcoholAire > limiteAlcohol) {
    //Desactivar arranque
    Serial.println("Arranque bloqueado por concentración de alcohol elevado"); 
  } else {
    //Habilitar arranque
    Serial.println("Arranque permitido.")
  }

  
}
