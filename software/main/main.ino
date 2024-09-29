#include "alcoholSensor.h"
//Pines
const int alcoholPin = A0;
const unsigned int pinPrueba = 13;

//Niveles
const int limiteAlcohol = 50;
int nivelAlcoholAire = 0;

//Configuración
const unsigned int baud = 9600;
const unsigned int bitsADC = 10;
int control = 0;
bool pruebaEnCurso = false;

//Objetos
alcoholSensor sensorDeAlcohol(alcoholPin, bitsADC);


void setup() {
  Serial.begin(baud);
  pinMode(pinPrueba, INPUT);

}

void loop() {
  control = sensorDeAlcohol.iniciarPrueba(pinPrueba);

  if (control != LOW && !pruebaEnCurso) {
    nivelAlcoholAire = sensorDeAlcohol.leerNivelAlcohol();

    Serial.println("Nivel de alcohol: " + String(nivelAlcoholAire));
    pruebaEnCurso = true;
    

    if (nivelAlcoholAire > limiteAlcohol) {
      //Desactivar arranque
      Serial.println("Arranque bloqueado por concentración de alcohol elevado."); 
    } else {
    //Habilitar arranque
    Serial.println("Arranque permitido.");
    }
  }

  if(control == LOW && pruebaEnCurso) {
    pruebaEnCurso = false;
  }

  //El programa se reinicia al enviarle algo por puerto serie
  if (Serial.available()){
    Serial.read();
    control = 0;
    pruebaEnCurso = false;
    Serial.println("Prueba reiniciada.");
  }
  delay(1000);
}
