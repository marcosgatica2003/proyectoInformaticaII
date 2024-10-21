#include "sensorHW481.h"

/**
* @brief Constructor de la clase sensorTemp
* @param p: valor para el dato miembro privado pin.
*
* Inicializa el pin y el objeto dht11 de la clase Bonezegei_DHT11.
* Inicializa la lectura del sensor con el método begin de la clase Bonezegei_DHT11.
*/

sensorTemp::sensorTemp(unsigned int p): pin(p), dht11(p) {
    dht11.begin();
}

/**
*@brief bool verificarPin();
* Este método verifica que el objeto dht11, el que controla las lecturas del sensor, tenga asignado un pin físicamente y lógicamente válido.
*/


bool sensorTemp::verificarPin(){
    return (pin != -1);
}

/**
*@brief void setPin(unsigned int p);
* Método para asignar un pin en caso de haber inicializado con un objeto de sensorTemp sin argumentos o para simplemente cambiar el pin donde está conectado la comunicación con el DHT11.
*/

void sensorTemp::setPin(unsigned int p) {
    pin = p;
}

/**
*@brief float leerHumedad();
* Verifica que exista un pin válido, en caso de ser cierto, llama a un método de la clase Bonezegei_DHT11 para leer la humedad y devuelve ese valor.
*/

float sensorTemp::leerHumedad() {

    if(!verificarPin()) {
        Serial.println("Error: pin no establecido.");
        return NAN;
    }

    return dht11.getHumidity();
}

/**
*@brief float leerTemperatura();
* Verifica que exista un pin válido, en caso de ser cierto, llama a un método de la clase Bonezegei_DHT11 para leer la temperatura y devuelve ese valor.
*/

float sensorTemp::leerTemperatura() {

    if(!verificarPin()) {
        Serial.println("Error: pin no establecido.");
        return NAN;
    }

    return dht11.getTemperature();
}

/**
*@brief bool verificarLectura();
* Verifica que exista un pin válido, en caso de ser cierto, comprueba que no se están recibiendo lecturas incorrectas o aleatorias del sensor.
*/

bool sensorTemp::verificarLectura() {

    if(!verificarPin()) {
        Serial.println("Error: pin no establecido.");
        return NAN;
    }

    bool lectura = true;

    if (isnan(dht11.getHumidity()) || isnan(dht11.getTemperature())) {
        lectura = false;
    }

    return lectura;
}

/**
*@brief void imprimirHum();
* Verifica que exista un pin válido, en caso de ser cierto, manda por puerto serie UART las lecturas de humedad.
*/

void sensorTemp::imprimirHum() {

    if(!verificarPin()) {
        Serial.println("Error: pin no establecido.");
    } else {
        Serial.print("Humedad: ");
        Serial.print(sensorTemp::leerHumedad());
        Serial.println(" %");
    }
}

/**
*@brief void imprimirHum();
* Verifica que exista un pin válido, en caso de ser cierto, manda por puerto serie UART las lecturas de temperatura.
*/

void sensorTemp::imprimirTemp() {

    if(!verificarPin()) {
        Serial.println("Error: pin no establecido.");
    } else {
        Serial.print("Temperatura: ");
        Serial.print(sensorTemp::leerTemperatura());
        Serial.println(" ºC");
    }
}

