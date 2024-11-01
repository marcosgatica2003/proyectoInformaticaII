#include "timer.h"

timer::timer(int pIngreso, int pReset, int p1, int p2, unsigned long t1, unsigned long t2): 
   pinIngreso(pIngreso),
   pinReset(pReset), 
   pinSalidaUno(p1), 
   pinSalidaDos(p2), 
   tiempoUno(t1), 
   tiempoDos(t2), 
   contON(false), 
   cont1(0) {}

void timer::iniciar() {
    pinMode(pinIngreso, INPUT);
    pinMode(pinReset, INPUT);
    pinMode(pinSalidaUno, OUTPUT);
    pinMode(pinSalidaDos, OUTPUT);
}

bool timer::tiempoUnoCumplido() {
    return (millis() - cont1 >= tiempoUno);
}

bool timer::tiempoDosCumplido() {
    return (millis() - cont1 >= tiempoDos);
}

void timer::actualizar() {
    unsigned long tiempoActual = millis();

    if (digitalRead(pinIngreso) && !contON) {
        contON = true;
        cont1 = tiempoActual;
    }

    if (contON && digitalRead(pinReset)) {
        cont1 = tiempoActual;
        digitalWrite(pinSalidaUno, LOW);
        digitalWrite(pinSalidaDos, LOW);
    }

    if (contON) {
        if (tiempoUnoCumplido()) {
            digitalWrite(pinSalidaUno, HIGH);
            if (tiempoDosCumplido()) {
                digitalWrite(pinSalidaDos, HIGH);
            }
        }
    }
}

