/**
* Ejemplo basico de cambio de color.
* @author Alex Vargas Benamburg (alex@vbalex.com)
* @date Sabado 26, Septiembre 2016
* @version 0.1
* @license CC-BY-SA
**/
#include <ColorTools.h>

#define NUM_PIXELES 10
#define PIN_PIXELES 7

NeoPixel luces = NeoPixel(NUM_PIXELES, PIN_PIXELES);
HSV hsv(0, 1.0, 1.0); // tono 0 saturacion 100% valor 100%
RGB rgb;

float velocidad = 0.025;

void setup() {
  luces.begin();
}

void loop() {
  //variables para colores

  //ciclo para cambio de color desde 0 hasta 360 aumentando en medio grado
  for(float tono = 0; tono<360; tono += velocidad){
    hsv.h = tono;
    //asignacion a todas las luces
    for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
      luces.setPixelColor(pixel,hsv);
    }
    luces.update();
  }
}
