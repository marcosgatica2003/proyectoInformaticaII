/**
 * @file main.cpp
 * @brief Sistema de control de cámaras frigoríficas.
 * Este proyecto utiliza un sistema baso en RFID, BUZZER, TIMER, RELOJ, SERVOMOTOR y Gestión de usuario
 * @author Grupo 06 - Informática II
 * @date Noviembre 2024
 */

//Inclusón de bibliotecas del proyecto
#include "libraries/RFID-RC522/RFIDLibs.h"
#include "libraries/DHT11-HW-481/DHT11Libs.h"
#include "libraries/TIMER/timerLibs.h"
#include "libraries/BUZZER-CLDZ/buzzerLibs.h"
/* #include "libraries/LCD-SCREEN/pantallaLCDLibs.h" */
#include "libraries/USERS-CONTROL/usuarioLibs.h"
#include "libraries/SERVO/servoLibs.h"
#include "libraries/CLOCK/clockLibs.h"

//Parámetros y pines
#define BAUD 9600 /**< Velocidad de comunicación del puerto serie en baudios */
/* #define OLED_RESET -1 */ /**< Pin de reset de la pantalla (innabilitado)
/* #define SCREEN_ADDRESS 0x3C */ /**Dirección de memoria I2C de la pantalla (innabilitado) */
#define PIN_INGRESO_TIMER 2 /**< Pin digital de ingreso para accionar el timer manualmente */
#define PIN_RESET_TIMER 3 /**< Pin digital de reset del timer */
#define PIN_SALIDA1_TIMER 4 /**< Salida digital 1 del timer */
#define PIN_SALIDA2_TIMER 5 /**< Salida digital 2 del timer */
#define PIN_SERVO_PUERTA 6 /**< Pin para controlar el servomotor con digital PWM */
#define PIN_CERRAR_SERVO_PUERTA A0 /**< Pin análogo / digital para cerrar la puerta con el servomotor */
#define PIN_BUZZER 8 /**< Pin digital Vcc para el buzzer y su secuencia de emisión. */
#define PIN_POTENCIOMETRO_BUZZER 5 /**< Pin análogo del Buzzer para dispositivos similares en modo activo (desactivado por ser pasivo) */
#define PIN_SENSOR_TEMPERATURA 2 /**< Pin para el sensor DHT11, usado para recibir la temperatura */
#define SS_PIN 10 ///< Pin SS (setting) para el módulo RFID
#define RST_PIN 9 ///< Pin RST (reset) para el módulo RFID

//Objetos y variables
float temperatura = 0; /**< Variable para almacenar la tamperatura laída. */
String temperaturaText = ""; /**< Cadena para mostrar la temperatura por LCD (innabilitado). */
const int pinCerrarPuerta = PIN_CERRAR_SERVO_PUERTA; /**< Pin para cerrar la puerta usando el servomotor. */
const int HORAS = __TIME__[0] * 10 + __TIME__[1] - '0' * 11; /**< Variable que almacena la hora al momento de compilar usando una macro de Arduino. */
const int MINUTOS = __TIME__[3] * 10 + __TIME__[4] - '0' * 11; /**< Variable que almacena los minutos al momento de compilar usando una macro de Arduino. */
const int SEGUNDOS = __TIME__[6] * 10 + __TIME__[7] - '0' * 11;/**< Variable que almacena los segundos al momento de compilar usando una macro de Arduino. */ 

accesoRFID tarjetaRFID(SS_PIN, RST_PIN, "87 9C 0A 4E");  /**< Objeto para acceso RFID con tarjeta. */
usuario elSalas("87 9C 0A 4E", "Joaquin", "Salas"); /**< Objeto usuario Joaquín Salas. */

accesoRFID llaveroRFID(SS_PIN, RST_PIN, "79 C3 C3 A2"); /**< Objeto para el acceso RFID con llavero. */
usuario paina("79 C3 C3 A2", "Gonza", "Paina"); /**< Objeto usuario Gonzalo Paina. */

buzzer elBuzzer(PIN_BUZZER, PIN_POTENCIOMETRO_BUZZER); /**< Objeto para inicializar el pin PWM del buzzer y su valor resistivo como potenciometro. */
timer elTimer(PIN_INGRESO_TIMER, PIN_RESET_TIMER, PIN_SALIDA1_TIMER, PIN_SALIDA2_TIMER, 3000, 6000); /**< Objeto elTimer que recibe como parámetros el pin para dar ON al timer, el reset, salida1, salida2 y siendo 3000 y 6000 ms el tiempo de funcionamiento. */
DHT11 sensor(PIN_SENSOR_TEMPERATURA); /**< Objeto para recibir datos del snesor DHT11 de temperatura. */

/* pantallaLCD laPantalla(SCREEN_ADDRESS); */ /**< Objeto que inicializa la pantalla con su dirección de memoria (innabilitado). */

puertaServo puerta(PIN_SERVO_PUERTA); /**< Objeto para controlar los pultos PWM del servomotor. */ 

reloj clock(HORAS, MINUTOS, SEGUNDOS); /**< Objeto reloj para gestionar la hora, pasándole como parámetros el tiempo actual obtenido por macros de Arduino. */

//Prototipos de funciones
/**
 * @brief bool verificarAcceso();
 * Verifica si el acceso está permitido a un usuario.
 * 
 * Esta función valida si la tarjeta o llavero RFID es válido y si el acceso se encuentra dentro del rango horario permitido.
 * 
 * @return true Si el acceso está permitido, false si es denegado.
 */
bool verificarAcceso();

/**
 * @brief bool rangoHorario();
 * Verifica si el acceso es dentro del rango horario permitido (08:00 - 23:00).
 * 
 * @return true Si el acceso está dentro del rango horario, false si no.
 */

bool rangoHorario();

/**
 * @brief accionarTimer();
 * Ejecuta las acciones relacionadas con el temporizador (sonidos del buzzer).
 */
void accionarTimer();

/**
 * @brief void setup(): Configuración inicial del sistema.
 * 
 * En el setup, se inicializan los módulos (RFID, buzzer, servo, temporizador, sensor,
 * etc.) y se configura la comunicación serie.
 */

void setup() {
  Serial.begin(BAUD); /**< Inicializa la comunicación serie. */
  tarjetaRFID.start(); llaveroRFID.start(); /**< Inicializa los objetos para el control del RFID. */
  //laPantalla.limpiar(); /**< Limpia la pantalla LCD (innabilitado). */
  elBuzzer.update(); /**< Función que hará que el buzzer tome el valor de la resistencia actual. */
  puerta.inicializar(); /**<Inicializa el servomotor, cerrando la puerta por defecto. */
  pinMode(pinCerrarPuerta, INPUT_PULLUP); /**< Configura el pin para cerrar la puerta con servomotor (en formato entrada para pulsador).*/
  digitalWrite(pinCerrarPuerta, LOW); /**< Configura el pin en bajo para la puerta con servomotor. */
}

/**
 * @brief void loop(): Bucle principal del sistema.
 * 
 * En el loop se leen constantemente la temperatura, se muestra en pantalla y se 
 * realizan las verificaciones de acceso mediante RFID. Si se permite el acceso, 
 * se abre la puerta y se activa el temporizador.
 */

void loop() {

  temperatura = sensor.readTemperature(); /**< Lee la temperatura desde el sensor DHT11*/
  temperaturaText = "Temp: " + String(temperatura) + " C"; /**< Se formatea la temperatura como texto string. */
  //laPantalla.pantallaTexto(temperaturaText, 0, 0, 2); /**< Muestra la temperatura en la pantalla LCD (innabilitado).*/

  /**
   * @brief if(Serial.available() > 0): control de puerto serie con mensajes.
   * Secuencia de if's para gestionar lo que devuelve el puerto serie según los mensajes que este reciba por el mismo canal Full-Duplex.
   */

  if(Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n'); /**< La variable comando se iniciliza con los datos recibidos por puerto serie, luego son mostrados imprimiendo "comando" en la terminal del puerto serie. */
    Serial.print("Comando recibido: ");
    Serial.println(comando);

  /**
   * @brief if(comando == "getTemp")
   * Solicitud para imprimir por puerto serie la temperatura detectada por DHT11.
   */


    if (comando == "getTemp") {
      Serial.println("------------------------------");
      Serial.print("Temperatura: ");
      Serial.print(String(temperatura));
      Serial.print("ºC\n");
      Serial.println("------------------------------");
      delay(2000);
    }

  /**
   * @brief if(comando == "getTime")
   * Solicitud para imprimir por puerto serie la hora actual del sistema.
   */

    if (comando == "getTime") {
      Serial.println("------------------------------");
      Serial.print("Hora: ");
      Serial.print(String(clock.getHoras()));
      Serial.print(":");
      Serial.print(String(clock.getMinutos()));
      Serial.print(":");
      Serial.print(String(clock.getSegundos()));
      Serial.println("------------------------------");
      delay(2000);      
    }

  /**
   * @brief if(comando == "force")
   * Solicitud para forzar las rutinas del timer, alarmas y servomotor sin necesidad de clave RFID ni limitaciones por horario.
   */

    if (comando == "force") {
      Serial.println("------------------------------");
      Serial.print("Entrada forzada!");
      Serial.println("------------------------------");
      delay(2000);  

      puerta.abrir(); 
      accionarTimer();
      elTimer.actualizar();

    }

  }

  /**
   * @brief if(digitalRead(pinCerrarPuerta) == HIGH)
   * Lee si se ha pulsado el pulsador correspondiente a cerrar el servomotor para cerrar la puerta.
   */

  if (digitalRead(pinCerrarPuerta) == HIGH) {

    Serial.println("------------------------------");
    Serial.println("Puerta cerrada.");
    Serial.println("------------------------------");


    puerta.cerrar(); 
  }

/**
 * @brief if(verificarAcceso())
 * Se llama a la función verificarAcceso().
 */

  if(verificarAcceso()){

/**
 * @brief if(elSalas.getID == "87 9C 0A 4E") y if(paina.getID() == "79 C3 C3 A2")
 * Estos la condición de estos if's es comparar los id de los objetos usuario con los id de llavero/tarjeta para permitir o no el acceso.
 */

    if(elSalas.getID() == "87 9C 0A 4E"){
      puerta.abrir();
      elSalas.incrementarAcceso();
      //laPantalla.limpiar(); 
      //laPantalla.pantallaTexto("Bienv. Salas", 0, 0, 2);

      Serial.println("------------------------------");
      Serial.println("Bienvenido!");
      Serial.println("------------------------------");

      accionarTimer();
      elTimer.actualizar();
    }

    if(paina.getID() == "79 C3 C3 A2"){
      puerta.abrir();
      paina.incrementarAcceso();
      //laPantalla.limpiar(); 
      //laPantalla.pantallaTexto("Bienv. Profe", 0, 0, 2);

      Serial.println("------------------------------");
      Serial.println("Bienvenido profe!");
      Serial.println("------------------------------");

      accionarTimer();
      elTimer.actualizar();
    }
  }
}

/**
 * @brief bool rangoHorario()
 * Verifica si se encuentra en el rango horario laboral. Imprime por puerto serie el resultado final.
 * @return true cuando el acceso está en un horario correcto, retorna false en caso que no.
 */

bool rangoHorario() {
  if(clock.getHoras() >= 8 && clock.getHoras() < 23) {
    Serial.println("------------------------------");
    Serial.println("En horario");
    Serial.println("------------------------------");

    return true; 
  }

  Serial.println("------------------------------");
  Serial.println("Fuera de horario");
  Serial.println("------------------------------");

  return false;
}

/**
 * @brief bool VerificarAcceso()
 * Función que autoriza las lecturas del llavero o la tarjeta, para ser leídas y verificar sus id.
 * Maneja también el return del rangoHorario().
 * @return false en todo momento hasta que se le acerque una tarjeta o llavero en el horario correcto.
 */

bool verificarAcceso () {
  if(tarjetaRFID.autorizar() || llaveroRFID.autorizar()) {
    if (rangoHorario()) { 
      Serial.println("------------------------------");
      Serial.println("Acceso permitido");
      Serial.println("------------------------------");
      delay(3000);
      //laPantalla.limpiar();
      //laPantalla.pantallaTexto("Acceso permitido", 0, 0, 2);
      return true;

    } else {
      //laPantalla.limpiar();
      //laPantalla.pantallaTexto("Fuera de horario", 0, 0, 2);
      
    }
  }
  

  return false;
}

/**
 *@brief void accionarTimer()
 *Controla los pulsos breves e intensos del buzzer en función a los tiempos del timer.
 */

void accionarTimer() {
  if(elTimer.tiempoUnoCumplido()) {
    elBuzzer.emitirSonidoBreve();
  }

  if(elTimer.tiempoDosCumplido()) {
    elBuzzer.emitirSonidoIntenso();
  }

}
