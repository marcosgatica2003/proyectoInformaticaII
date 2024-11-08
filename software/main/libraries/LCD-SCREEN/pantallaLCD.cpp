#include "pantallaLCD.h"

pantallaLCD::pantallaLCD(uint8_t width, uint8_t height, int address): pantalla(width, height, &Wire, -1), _address(address) {}

bool pantallaLCD::begin() {
    if(!pantalla.begin(SSD1306_SWITCHCAPVCC, _address)) {
        Serial.println(F("Pantalla OLED no encontrada"));
        return false;
    }

    pantalla.clearDisplay();
    pantalla.display();
    return true;
}

void pantallaLCD::limpiar() {
    pantalla.clearDisplay();
    pantalla.display();
}

void pantallaLCD::pantallaTexto(const String& text, int x, int y, int textSize) {
    pantalla.setTextSize(textSize);
    pantalla.setTextColor(SSD1306_WHITE);
    pantalla.setCursor(x, y);
    pantalla.print(text);
    pantalla.display();
}

