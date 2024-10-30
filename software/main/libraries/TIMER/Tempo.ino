const unsigned long temporizador = 3000;
unsigned long cont1;
int pinIngreso = 2, pin2 = 4, pin3 = 5, pinReset = 3;
bool contON = false;

void setup() {
  pinMode (pinIngreso, INPUT);
  pinMode (pinReset, INPUT);
  pinMode (pin2, OUTPUT);
  pinMode (pin3, OUTPUT);
}

void loop() {
  
  if (digitalRead (pinIngreso) && !contON) {
    contON = true;
    cont1 = millis();
  }

  if (contON && digitalRead (pinReset)) {
    cont1 = millis();
    digitalWrite (pin2, LOW);
    digitalWrite (pin3, LOW);
  }

  if (!digitalRead (pinIngreso)) {
    contON = false;
    digitalWrite (pin2, LOW);
    digitalWrite (pin3, LOW);
  }
  
  if (contON) {
    if (millis() - cont1 >= temporizador) {
      digitalWrite (pin2, HIGH);
      if (millis() - cont1 >= (temporizador*2)) {
        digitalWrite (pin3, HIGH);
      }
    }
  }

   

}
