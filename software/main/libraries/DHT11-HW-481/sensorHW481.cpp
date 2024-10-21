#include "sensorHW481.h"
#define DHTTYPE DHT11  
#define DHTPIN 2

sensorTemp::sensorTemp(): pin(DHTPIN), dht11(DHTPIN, DHTTYPE) {
    dht11.begin();
}

float sensorTemp::leerHumedad() {
    return dht11.getHumidity();
}

float sensorTemp::leerTemperatura() {
    return dht11.getTemperature();
}

bool sensorTemp::verificarLectura() {
    bool lectura = true;

    if (isnan(dht11.getHumidity()) || isnan(dht11.getTemperature())) {
        lectura = false;
    }

    return lectura;
}

void sensorTemp::imprimirHum() {
    Serial.print("Humedad: ");
    Serial.print(sensorTemp::leerHumedad());
    Serial.println(" %");
}

void sensorTemp::imprimirTemp() {
    Serial.print("Temperatura: ");
    Serial.print(sensorTemp::leerTemperatura());
    Serial.println(" ºC");

}

