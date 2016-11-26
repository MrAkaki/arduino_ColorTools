/**
* Saturacion_POT
* Ejemplo de llanta de color, se modifica la saturacion mediante un potenciometro
* conectado al pin A0, se emplea la regla de tres(https://es.wikipedia.org/wiki/Regla_de_tres)
* para calcular el angulo(posicion) de cada uno de los pixeles
* ademas de usa una formula para que el cambio de valores no
* sea brusco, en si es una paradoja de Zenon( La dicotomia)
* https://es.wikipedia.org/wiki/Paradojas_de_Zen%C3%B3n#La_dicotom.C3.ADa
* 
*
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


//velocidad de animacion
const float VELOCIDAD = 0.01;
const float PROP_PIXEL = 360./(float)NUM_PIXELES;
const float PROP_AIN = 1./1024.;

//variables para colores
//El tono y la saturacion seran modificados constantemente
HSV hsv(0., 0., 0.5); // tono 0, saturacion 0%, valor 50%
RGB rgb;

void setup() {
  luces.begin();
}

void loop() {
  uint16_t aIn = analogRead(A0);
  float nSaturacion =  aIn*PROP_AIN;

  //Formula sensilla para cresimiento lento
  hsv.s += (nSaturacion - hsv.s)*VELOCIDAD;

  //ciclo para definir color de cada pixel
  for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
    hsv.h = pixel*PROP_PIXEL;
    HSV2RGB(hsv,&rgb); // convercion de HSV a RGB
    luces.setPixelColor(pixel ,rgb.r ,rgb.g ,rgb.b);
  }
    luces.show();;

}
