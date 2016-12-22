/**
* LlantaEstatica
* Ejemplo de llanta de color estatica, se emplea la
* regla de tres(https://es.wikipedia.org/wiki/Regla_de_tres)
* para calcular el angulo(posicion) de cada uno de los pixeles.
*
* @author Alex Vargas Benamburg (alex@vbalex.com)
* @date Sabado 26, Septiembre 2016
* @version 0.1
* @license CC-BY-SA
**/

#include <ColorTools.h>

#define NUM_PIXELES 10
#define PIN_PIXELES 7

NeoPixel luces = NeoPixel(NUM_PIXELES, PIN_PIXELES,);

//Uso regla de tres, calculo la proporcion para evitar calculos innesesarios
float proporcion = 360./(float)NUM_PIXELES;

void setup() {
  luces.begin();
}

void loop() {
  //variables para los modelos de color
  HSV hsv(0, 1.0, 1.0); // tono 0 saturacion 100% valor 100%
//ciclo para definir color de cada pixel
  for(uint8_t pixel=0; pixel<luces.numPixels();++pixel){
    hsv.h = pixel*proporcion; // uso de regla de 3
    luces.setPixelColor(pixel ,hsv);
  }
  luces.update();
}
