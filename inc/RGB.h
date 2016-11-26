#ifndef RGB_H
#define RGB_H
#include "HSV.h"

/**
* Clase para modelo de color RGB
* @author Alex Vargas Benamburg
* @email alex@vbalex.com
* @license CC-BY-SA
**/
class RGB {
  public:
    // variable para red, rojo
    uint8_t r;
    // variable para green, verde
    uint8_t g;
    // varialbe para blue, azul
    uint8_t b;

    //Contructor por defecto
    RGB(){}

    //Contructor con parametros
    RGB(uint8_t r,uint8_t g, uint8_t b){
      this->r = r;
      this->g = g;
      this->b = b;
    }

    //Contructor de copia
    RGB(const RGB &otro){
      this->r = otro.r;
      this->g = otro.g;
      this->b = otro.b;
    };

    //Sobrecarga de operador =
    RGB& operator=(const RGB &otro){
      this->r = otro.r;
      this->g = otro.g;
      this->b = otro.b;
      return *this;
    }
};
#endif
