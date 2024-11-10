#include "pantallaLCD.h"

pantallaLCD::pantallaLCD(
        uint8_t width, 
        uint8_t height,
        uint8_t address
        ): pantalla(width, height, &Wire, -1), _address(address) {

    if(!pantalla.begin(SSD1306_SWITCHCAPVCC, _address)) {
        Serial.println(F("Pantalla OLED no encontrada"));
    }

    pantalla.clearDisplay();
    pantalla.display();

}

void pantallaLCD::limpiar() {
    pantalla.clearDisplay();
    pantalla.display();
}

void pantallaLCD::pantallaTexto(const String& text, int x, int y, int textSize) {
    pantalla.setTextSize(textSize);
    pantalla.setTextColor(SSD1306_WHITE);
    pantalla.setCursor(x, y);
    pantalla.println(text);
    pantalla.display();
}

