/**
* Ejemplo basico de cambio de color.
* @author Alex Vargas Benamburg (alex@vbalex.com)
* @date Sabado 26, Septiembre 2016
* @version 0.1
* @license CC-BY-SA
**/
#include <Adafruit_NeoPixel.h>
#include <ColorTools.h>

#define NUM_PIXELES 10
#define PIN_PIXELES 17

Adafruit_NeoPixel luces = Adafruit_NeoPixel(NUM_PIXELES, PIN_PIXELES, NEO_GRB + NEO_KHZ800);

void setup() {
  luces.begin();
}

void loop() {
  //variables para colores
  HSV hsv(0, 1.0, 1.0); // tono 0 saturacion 100% valor 100%
  RGB rgb;
  //ciclo para cambio de color desde 0 hasta 360 aumentando en medio grado
  for(hsv.h = 0; hsv.h<360; hsv.h+= 0.5){
    HSV2RGB(hsv, &rgb);// Comvercion de hsv a rgb
    //asignacion a todas las luces
    for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
      luces.setPixelColor(pixel, rgb.r, rgb.g, rgb.b);
    }
    luces.show();
    delay(50);
  }
}
