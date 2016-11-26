#include <Adafruit_NeoPixel.h>
#include <ColorTools.h>

#define NUM_PIXELES 10
#define PIN_PIXELES 17

Adafruit_NeoPixel luces = Adafruit_NeoPixel(NUM_PIXELES, PIN_PIXELES, NEO_GRB + NEO_KHZ800);

//Uso regla de tres, calculo la proporcion para evitar calculos innesesarios
float proporcion = 360./(float)NUM_PIXELES;

void setup() {
  luces.begin();
}

void loop() {
  //variables para colores
  HSV hsv(0, 1.0, 1.0); // tono 0 saturacion 100% valor 100%
  RGB rgb;
  //clico para definir color de cada pixel
  for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
    hsv.h = pixel*proporcion; // uso de regla de 3
    HSV2RGB(hsv,&rgb); // combercion de HSV a RGB
    luces.setPixelColor(pixel ,rgb.r ,rgb.g ,rgb.b);
  }
  luces.show();
}
