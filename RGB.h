#pragma once

class RGB;
#include <math.h>
#include <Arduino.h>
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
    RGB();

    //Contructor con parametros
    RGB(uint8_t& r,uint8_t& g, uint8_t& b);

    //Contructor de copia
    RGB(const RGB &otro);

    /**
     * Transforma del modelo de color RGB al modelo de color HSV.
     * @param RGB &input, entrada RGB a tranformar.
     * @param HSV *responce, salida HSV tranformado.
     **/
    void toHSV(HSV& otro);

    //Sobrecarga de operador =
    RGB& operator=(const RGB &otro);
    //Sobrecarga de operador =
    RGB& operator=(const HSV &otro);
    //Sobrecarga de operador =
    RGB& operator=(const uint32_t color);

};
