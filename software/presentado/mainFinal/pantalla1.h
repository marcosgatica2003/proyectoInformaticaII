#ifndef PANTALLA1_H
#define PANTALLA1_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

extern Adafruit_SSD1306 pantalla; 

void imprimirPantalla();
void imprimirPuertaAbierta();
void imprimirPuertaCerrada();
void timerUNO();
void timerDOS();
void timerReset();
void getTemp();
void imprimirServo();
void imprimirDenegado();
void imprimirTarjeta();

#endif
