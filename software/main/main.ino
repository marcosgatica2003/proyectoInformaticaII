/**
* @file main.ino
* @brief Programa principal para controlar el acceso a una cámara frigorífica usando RFID.
* 
* @brief RFIDLibs.h 
* Este archivo de cabecera contiene lo necesario para usar el módulo RFID-RC522
*/

//#include "libraries/RFID-RC522/RFIDLibs.h"
//#include "libraries/DHT11-HW-481/DHT11Libs.h"
#include "libraries/TIMER/timerLibs.h"
#include "libraries/BUZZER-CLDZ/buzzerLibs.h"

#define SS_PIN 10 ///< Pin SS para el módulo RFID
#define RST_PIN 9 ///< Pin RST para el módulo RFID
#define BAUD 9600
#define INGRESO_TIMER 2
#define RESET_TIMER 3
#define SALIDA1_TIMER 4
#define SALIDA2_TIMER 5
#define PIN_BUZZER 6
#define PIN_POTENCIOMETRO_BUZZER A0

buzzer elBuzzer(PIN_BUZZER, PIN_POTENCIOMETRO_BUZZER);
timer elTimer(INGRESO_TIMER, RESET_TIMER, SALIDA1_TIMER, SALIDA2_TIMER, 3000, 6000, 50);

void setup() {
  Serial.begin(BAUD);
}

void loop() {
  elBuzzer.update();

  if(elTimer.tiempoUnoCumplido()) {
    elBuzzer.emitirSonidoSuave();
  }

  if(elTimer.tiempoDosCumplido()) {
    elBuzzer.emitirSonidoFuerte();
  }

}



/*accesoRFID tarjetaRFID(SS_PIN, RST_PIN, "87 9C 0A 4E"); ///< Instancia del acceso RFID para la cámara frigorífica. */
/*accesoRFID llaveroRFID(SS_PIN, RST_PIN, "79 C3 C3 A2"); ///< Instancia del acceso RFID para la cámara frigorífica. */

/*DHT11 sensor(2); //Pin 2 digital Arduino */

/*/1** */
/** @brief bool verificarAcceso() */
/** */ 
/** Función que devuelve true si alguna llave tiene permiso para entrar. */
/**/ 

/*bool verificarAcceso () { */
/*  bool verif = false; */

/*  if(tarjetaRFID.autorizar() || llaveroRFID.autorizar()) { */

/*    Serial.println("Autorizado"); */
/*    verif = true; */

/*  } else { */
/*    Serial.println("Denegado"); */
/*  } */
  
/*  return verif; */
/*} */

/*/1** */
/** @brief void setup() */
/** */ 
/** Inicializa la comunicación serial y el módulo RFID. */
/**/ 

/*void setup() { */
/*  Serial.begin(9600); */
/*  tarjetaRFID.start(); llaveroRFID.start(); */
/*  setPinDHT11 (sensor, -1); */
/*} */

/*void loop() { */
/*  if(verificarAcceso()){ */
/*    //Abrir puerta */
/*  } */

/*  Serial.print("Temperatura: "); */
/*  Serial.print(sensor.readTemperature()); */
/*  Serial.print(" ºC"); */
    
/*  delay(2000); //Esto deberíamos quitarlo luego. */

/*} */

