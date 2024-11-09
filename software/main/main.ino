#include "libraries/RFID-RC522/RFIDLibs.h"
#include "libraries/DHT11-HW-481/DHT11Libs.h"
#include "libraries/TIMER/timerLibs.h"
#include "libraries/BUZZER-CLDZ/buzzerLibs.h"
#include "libraries/LCD-SCREEN/pantallaLCDLibs.h"
#include "libraries/USERS-CONTROL/usuarioLibs.h"
#include "libraries/SERVO/servoLibs.h"

//Parámetros
#define BAUD 9600
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define PIN_INGRESO_TIMER 2
#define PIN_RESET_TIMER 3
#define PIN_SALIDA1_TIMER 4
#define PIN_SALIDA2_TIMER 5
#define PIN_SERVO_PUERTA 11
#define PIN_CERRAR_SERVO_PUERTA 12
#define PIN_BUZZER 6
#define PIN_POTENCIOMETRO_BUZZER A0
#define PIN_SENSOR_TEMPERATURA 7
#define SS_PIN 10 ///< Pin SS para el módulo RFID
#define RST_PIN 9 ///< Pin RST para el módulo RFID

//Objetos y variables
accesoRFID tarjetaRFID(SS_PIN, RST_PIN, "87 9C 0A 4E"); 
usuario elSalas("87 9C 0A 4E", "Joaquin", "Salas");

accesoRFID llaveroRFID(SS_PIN, RST_PIN, "79 C3 C3 A2"); 
usuario paina("79 C3 C3 A2", "Gonza", "Paina");

buzzer elBuzzer(PIN_BUZZER, PIN_POTENCIOMETRO_BUZZER);
timer elTimer(PIN_INGRESO_TIMER, PIN_RESET_TIMER, PIN_SALIDA1_TIMER, PIN_SALIDA2_TIMER, 3000, 6000);
DHT11 sensor(PIN_SENSOR_TEMPERATURA); 

pantallaLCD laPantalla(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_ADDRESS);

puertaServo puerta(PIN_SERVO_PUERTA);

float temperatura = 0;
String temperaturaText = "";
const int pinCerrarPuerta = PIN_CERRAR_SERVO_PUERTA;

//Prototipos de funciones
bool verificarAcceso();
void accionarTimer();

void setup() {
  Serial.begin(BAUD);
  tarjetaRFID.start(); llaveroRFID.start();
  laPantalla.begin(); laPantalla.limpiar();
  elBuzzer.update(); //Esto hará que el buzzer tome el valor de la resistencia actual
  puerta.inicializar(); pinMode(pinCerrarPuerta, INPUT_PULLUP);
}

void loop() {

  temperatura = sensor.readTemperature();
  temperaturaText = "Temp: " + String(temperatura) + " C";
  laPantalla.limpiar(); laPantalla.pantallaTexto(temperaturaText, 0, 0, 2);

  if (digitalRead(pinCerrarPuerta) == HIGH) {
    puerta.cerrar(); 
  }

  if(verificarAcceso()){
    if(elSalas.getID() == "87 9C 0A 4E"){
      puerta.abrir();
      elSalas.incrementarAcceso();
      laPantalla.limpiar(); 
      laPantalla.pantallaTexto("Bienv. Salas", 0, 0, 2);
      accionarTimer();
      elTimer.actualizar();
    }

    if(paina.getID() == "79 C3 C3 A2"){
      puerta.abrir();
      paina.incrementarAcceso();
      laPantalla.limpiar(); 
      laPantalla.pantallaTexto("Bienv. Profe", 0, 0, 2);
      accionarTimer();
      elTimer.actualizar();
    }
  }
}

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

void accionarTimer() {
  if(elTimer.tiempoUnoCumplido()) {
    elBuzzer.emitirSonidoSuave();
  }

  if(elTimer.tiempoDosCumplido()) {
    elBuzzer.emitirSonidoFuerte();
  }

}
