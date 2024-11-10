#include "pantallaLCD.h"

pantallaLCD::pantallaLCD(uint8_t address): _pantalla(128, 32, &Wire, -1), _address(address) {

    if(!_pantalla.begin(SSD1306_SWITCHCAPVCC, _address)) {
        Serial.println(F("Pantalla OLED no encontrada"));
        while(true);
    }
    
    limpiar();

}

void pantallaLCD::limpiar() {
    this->_pantalla.clearDisplay();
    this->_pantalla.display();
}

void pantallaLCD::pantallaTexto(const String& text, int x, int y, int textSize) {
    this->_pantalla.clearDisplay();
    this->_pantalla.setTextSize(textSize);
    this->_pantalla.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    this->_pantalla.setCursor(x, y);
    this->_pantalla.println(text);
    this->_pantalla.display();
    delay(1000);
}

