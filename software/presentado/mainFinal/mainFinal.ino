#include "pantalla1.h"
#include <DHT11.h>
#include <Servo.h>  // Incluye la librería para controlar el servo

#define BOTON_PIN 2  // Pin del botón (simula la tarjeta)
#define LED_PIN 7     // Pin del LED
#define SERVO_PIN 9   // Pin donde está conectado el servo

Servo miServo;        // Crea un objeto de tipo Servo
bool mostrarMensaje = false;
bool accesoPermitido = false;  // Variable que indica si el acceso está permitido

unsigned long tiempoInicio = 0; // Variable para almacenar el tiempo de inicio del temporizador
unsigned long DURACION_ACCESO = 10000; // Duración del acceso permitido en milisegundos (10 segundos)
unsigned long segundosPrevios = 0; // Para rastrear los segundos transcurridos
// Variables para antirrebote
unsigned long ultimaLecturaBoton = 0; // Momento de la última lectura del botón
const unsigned long TIEMPO_REBOTE = 50; // Tiempo para considerar un rebote (en milisegundos)
bool estadoBotonAnterior = HIGH; // Estado anterior del botón (usando pull-up)

unsigned long temporizador = 5000;
unsigned long cont1;
int pinIngreso =11; //Llave que inicia el temporizador y tambien lo apaga, es condicion prenderlo para poder ingresar y debe ser apagado al salir
int pin2 = 4, pin3 = 5; //Salidas, corresponderian a buzzer bajo e intenso
int pinReset = 3; //Pulsador que reinicia el tiempo
bool contON = false; //variable que indica si el contador esta encendido
bool estado_puerta = false; //variable utilizada para imprimir mensaje
int estadoAnteriorIngreso = LOW; //variable utilizada para un flanco
int cant_accesos = 0;
//bool forzarSalida = false; 

int pinSensorTemp = 10;
              
DHT11 sensorTemperatura(pinSensorTemp);  

void setup() {
  Serial.begin(9600);
  pinMode (pinIngreso, INPUT);
  pinMode (pinReset, INPUT_PULLUP);
  pinMode (pin2, OUTPUT);
  pinMode (pin3, OUTPUT);
  digitalWrite (pin2, LOW);
  digitalWrite (pin3, LOW);
  imprimirPantalla(); 
  pinMode(BOTON_PIN, INPUT_PULLUP);      // Configura el pin del botón como entrada con pull-up interno
  pinMode(LED_PIN, OUTPUT);              // Configura el pin del LED como salida
  miServo.attach(SERVO_PIN);             // Asocia el pin del servo con el objeto Servo
  miServo.write(0);                      // Posición inicial del servo (0 grados)
  Serial.println("Esperando tarjeta ...");
}

void loop() {
 int estadoActualIngreso = digitalRead(pinIngreso); //Variable detectora de flancos
 bool estadoBotonActual = digitalRead(BOTON_PIN);



    /*if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n'); // Leer comando desde la PC

        if (comando.startsWith("Tiempo Servo=")) {
            DURACION_ACCESO = comando.substring(15).toInt(); // Actualiza tiempoServo
            Serial.println("tiempoServo actualizado.");
        } else if (comando.startsWith("Tiempo previo a la alarma=")) {
            temporizador = comando.substring(16).toInt(); // Actualiza tiempoAcceso
            Serial.println("tiempoAcceso actualizado.");
        } else if (comando == "getTemp") {
            int temperatura = sensorTemperatura.readTemperature();
            Serial.print("Temperatura: ");
            Serial.print(temperatura);
            Serial.println(" ºC");// Responde con el valor actual de la temperatura
        } else if (comando == "cantidad de accesos") {
            Serial.print("Cantidad de accesos a la camara: ");
            Serial.println(cant_accesos); // Responde con el valor actual del contador
        } else if (comando == "Forzar Entrada") {
           digitalWrite(LED_PIN, HIGH);      // Enciende el LED para indicar acceso
           miServo.write(90); 
           Serial.println("Entrada forzada");
        }
    }*/


 if(Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    if (comando == "getTemp") {
      int temperatura = sensorTemperatura.readTemperature();
      Serial.print("Temperatura: ");
      Serial.print(temperatura);
      Serial.println(" ºC");
    }
    if (comando == "forzar entrada") {  
      digitalWrite(LED_PIN, HIGH);      // Enciende el LED para indicar acceso
      miServo.write(90); 
      Serial.println("Entrada forzada");
    }
    if (comando == "cantidad de accesos") {
      Serial.print("Cantidad de accesos a la camara: ");
      Serial.println(cant_accesos);
    }
  
    if (comando == "tiempo") {
      Serial.println("Recibido comando para cambiar el temporizador");
      while(Serial.available() == 0);
      String nuevoValor = Serial.readStringUntil('\n');
      nuevoValor.trim();
      Serial.print("Cadena recibida: ");
      Serial.println(nuevoValor);
      unsigned long nuevoTemporizador = nuevoValor.toInt();
      Serial.print("Temporizador anterior: ");
      Serial.println(temporizador);
      Serial.print("Nuevo Temporizador: ");
      temporizador = nuevoTemporizador;
      Serial.println(temporizador);
    }

    if (comando == "tiempoServo") {
      Serial.println("Recibido comando para cambiar el tiempo servo");
      while(Serial.available() == 0);
      String nuevoValor = Serial.readStringUntil('\n');
      nuevoValor.trim();
      Serial.print("Cadena recibida: ");
      Serial.println(nuevoValor);
      unsigned long nuevoTemporizador = nuevoValor.toInt();
      Serial.print("Temporizador anterior: ");
      Serial.println(DURACION_ACCESO);
      Serial.print("Nuevo Temporizador: ");
      DURACION_ACCESO = nuevoTemporizador;
      Serial.println(DURACION_ACCESO);
    }
  }
  //Bloque if que imprime si la puerta se encuentra cerrada, lo hace por unica vez, hasta otra salida 
  if (!estado_puerta) {
    Serial.println ("Puerta cerrada");
     imprimirPuertaCerrada();
    
    
    estado_puerta = true;
  }

  
  // Antirrebote: verifica si el estado cambió y ha pasado suficiente tiempo
  if (estadoBotonActual != estadoBotonAnterior && (millis() - ultimaLecturaBoton > TIEMPO_REBOTE)) {
    ultimaLecturaBoton = millis(); // Actualiza el tiempo de la última lectura válida

    // Si el botón fue presionado (pasó de HIGH a LOW)
    if (estadoBotonActual == LOW && !accesoPermitido) {
      accesoPermitido = true;           // Activar el acceso
      tiempoInicio = millis();          // Inicia el conteo del temporizador
      segundosPrevios = 0;              // Reinicia el contador de segundos
      Serial.println("Acceso concedido, personal autorizado.");
      imprimirServo();
      digitalWrite(LED_PIN, HIGH);      // Enciende el LED para indicar acceso
      miServo.write(90);                // Mueve el servo a 90 grados
      
    }
  }
  

  estadoBotonAnterior = estadoBotonActual; // Actualiza el estado anterior del botón

  // Si el acceso está permitido, verifica si ha pasado el tiempo permitido
  if (accesoPermitido) {
    // Calcula el tiempo transcurrido en segundos
    unsigned long tiempoTranscurrido = millis() - tiempoInicio;
    unsigned long segundosActuales = tiempoTranscurrido / 1000;
  
  
    // Verifica si el tiempo transcurrido ha superado la duración permitida
    if (tiempoTranscurrido >= DURACION_ACCESO) {
      if(!digitalRead(pinIngreso)){
      accesoPermitido = false;        // Reinicia la variable para la siguiente vez
      digitalWrite(LED_PIN, LOW);     // Apaga el LED
      miServo.write(0);               // Mueve el servo de regreso a 0 grados
        imprimirDenegado();
        Serial.println("\n");
      Serial.println("Puerta cerrada");
      Serial.println("Esperando tarjeta ...");
    
    }
    }
  }
  
  if (digitalRead (pinIngreso) && !contON) { //si se detecta un ingreso (rfid y llave selectora) y el contador esta apagado, lo enciende
    contON = true;
    cont1 = millis();
    Serial.println("Puerta abierta, bienvenido!");
    imprimirPuertaAbierta();
   cant_accesos++;
  }

  if (contON && !digitalRead(pinReset)) { //bloque if que reinicia el tiempo
    cont1 = millis();
    digitalWrite (pin2, LOW);
    digitalWrite (pin3, LOW);
    //Serial.println("Timer reset!");
    timerReset();
  }
  
  if (!digitalRead (pinIngreso)) { //si no hay nadie dentro, se apagan las salidas y el contador. Se pone a false el ingreso. Es utilizado tambien para indicar que salimos de la camara
    contON = false;
    digitalWrite (pin2, LOW);
    digitalWrite (pin3, LOW);
    if (estadoAnteriorIngreso == HIGH && estadoActualIngreso == LOW) { //Detector de flanco negativo para imprimir el mensaje "Puerta cerrada" por unica vez nuevamente
    estado_puerta = false;
    }
  }
  
  if (contON) { //si el contador esta encendido, cuenta los tiempos y activa las respectivas salidas si se cumplen los if
    if (millis() - cont1 >= temporizador) {
     digitalWrite (pin2, HIGH);
      timerUNO(); 
      if (millis() - cont1 >= (temporizador*2)) {
        digitalWrite(pin3, HIGH); 
      }
    }
  }

  estadoAnteriorIngreso = estadoActualIngreso; //Actualiza el valor para el flanco

}
