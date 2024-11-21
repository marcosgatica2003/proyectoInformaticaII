#include "libraries/BUZZER-CLDZ/buzzerLibs.h"
#include "libraries/CLOCK/clockLibs.h"
#include "libraries/DHT11-HW-481/DHT11Libs.h"
#include "libraries/LCD-SCREEN/pantallaLCDLibs.h"
#include "libraries/RFID-RC522/RFIDLibs.h"
#include "libraries/SERVO/servoLibs.h"
#include "libraries/TIMER/timerLibs.h"
#include "libraries/USERS-CONTROL/usuarioLibs.h"


#define SS_PIN 10 ///< Pin SS (setting) para el módulo RFID
#define RST_PIN 9 ///< Pin RST (reset) para el módulo RFID


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("");
}
