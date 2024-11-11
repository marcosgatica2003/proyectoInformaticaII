#ifndef PANTALLALCD_H
#define PANTALLALCD_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

class pantallaLCD {
    public:
        pantallaLCD(uint8_t address);
        void limpiar();
        void pantallaTexto(const String& text, int x, int y, int textSize);
        
    private:
        Adafruit_SSD1306 _pantalla;
        int _address;
};

#endif

