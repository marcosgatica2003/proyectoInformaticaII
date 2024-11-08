#ifndef PANTALLALCD_H
#define PANTALLALCD_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

class pantallaLCD {
    public:
        pantallaLCD(uint8_t width, uint8_t height, int address);
        bool begin();
        void limpiar();
        void pantallaTexto(const String& text, int x, int y, int textSize);
        
    private:
        Adafruit_SSD1306 pantalla;
        int _address;
};

#endif

