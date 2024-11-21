 #include "pantalla1.h"


Adafruit_SSD1306 pantalla(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




void imprimirPantalla() {
    if (!pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("No se pudo encontrar una pantalla OLED"));
        while (true);
    }
    pantalla.clearDisplay();
    pantalla.setTextColor(SSD1306_WHITE);
}

void imprimirPuertaAbierta() {
  pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Puerta Abierta\n");
  pantalla.print("Bienvenido!");
  pantalla.display();  // Actualizar pantalla
}

void imprimirPuertaCerrada() {
   pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Puerta Cerrada\n");
  pantalla.print("Esperando tarjeta ...");
  pantalla.display();  // Actualizar pantalla
}

void timerUNO() {
  pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Timer encendido!");
  pantalla.display();  // Actualizar pantalla
}


void timerDOS() {
  pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Timer 2 ON");
  pantalla.display();  // Actualizar pantalla
}

void timerReset(){
  pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Tiempo reiniciado");
  pantalla.display();  // Actualizar pantalla
}

void imprimirServo(){
   pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Acceso concedido!\n");
  pantalla.print("Personal autorizado.");
  pantalla.display();  // Actualizar pantalla
}

void imprimirDenegado(){
 pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Puerta cerrada\n");
  pantalla.print("Esperando tarjeta ...");
  pantalla.display();  // Actualizar pantalla
}

void imprimirTarjeta(){
  pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Esperando tarjeta ...");
  pantalla.display();  // Actualizar pantalla
}
/*
void getTemp(){
  int temperatura = sensorTemperatura.readTemperature();
  
 pantalla.clearDisplay();  // Limpiar pantalla
  pantalla.setTextSize(1);  // Tamaño del texto
  pantalla.setTextColor(SSD1306_WHITE);  // Color del texto
  pantalla.setCursor(0, 0);  // Posición inicial del texto
  pantalla.print("Temperatura: ");
  pantalla.println(temperatura);
  pantalla.print(" ºC");
  pantalla.display();  // Actualizar pantalla
}*/
