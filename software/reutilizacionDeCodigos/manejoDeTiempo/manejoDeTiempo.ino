#include "clock.h"

const int HORAS = __TIME__[0] * 10 + __TIME__[1] - '0' * 11;
const int MINUTOS = __TIME__[3] * 10 + __TIME__[4] - '0' * 11;
const int SEGUNDOS = __TIME__[6] * 10 + __TIME__[7] - '0' * 11;

reloj clock(HORAS, MINUTOS, SEGUNDOS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  clock.actualizar();
  Serial.print("Hora:\t");
  Serial.print(clock.getHoras()); 
  Serial.print(":"); 
  Serial.print(clock.getMinutos());
  Serial.print(":"); 
  Serial.print(clock.getSegundos());
  Serial.print("\n");
  delay(1000);
}
