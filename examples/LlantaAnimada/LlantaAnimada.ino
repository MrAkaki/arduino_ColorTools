#include <Adafruit_NeoPixel.h>
#include <ColorTools.h>

#define NUM_PIXELES 10
#define PIN_PIXELES 17

Adafruit_NeoPixel luces = Adafruit_NeoPixel(NUM_PIXELES, PIN_PIXELES, NEO_GRB + NEO_KHZ800);

//calculo proporciones para evitar calculos innesesarios
const float propPixel = (2.*PI)/(float)NUM_PIXELES; // posicion de cada pixel
const float propSin = 360./2; // mapes de 2(resultado de seno + 1) a 360(tono en hsv)

//velocidad de animacion
const float velocidad = 0.02;

void setup() {
  luces.begin();
}

void loop() {
  //variables para colores
  HSV hsv(0, 1.0, 1.0); // tono 0 saturacion 100% valor 100%
  RGB rgb;
  //cliclo de animacion de movimiento
  for(float p = -PI; p<PI; p+=velocidad){
    //clico para definir color de cada pixel
    for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
      float val = sin(pixel*propPixel + p) + 1;
      hsv.h = val*propSin;
      HSV2RGB(hsv,&rgb); // combercion de HSV a RGB
      luces.setPixelColor(pixel ,rgb.r ,rgb.g ,rgb.b);
    }
    luces.show();;
  }
}
