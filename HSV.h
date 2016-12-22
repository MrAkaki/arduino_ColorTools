#pragma once

/**
* Clase para modelo de color HSV
* @author Alex Vargas Benamburg
* @email alex@vbalex.com
* @license CC-BY-SA
**/

class HSV;
#include <math.h>
#include <Arduino.h>
#include "RGB.h"

class HSV {
  public:
    // variable para Hue, tono
    float h;
    // variable para Saturation, saturacion
    float s;
    // variable para Value, valor
    float v;

    //Constructor por defecto
    HSV();

    //Constructor con parametros
    HSV(float h,float s, float v);

    //Contructor de copia
    HSV(const HSV &otro);

    /**
     * Transforma del modelo de color HSV al modelo de color RGB.
     * @param HSV &input, entrada HSV a tranformar.
     * @param RGB *responce, salida RGB tranformado.
     **/
    void toRGB(RGB& otro);
    //Sobrecarga de operador =
    HSV& operator=(const HSV &otro);
    //Sobrecarga de operador =
    HSV& operator=(const RGB &otro);
    //Sobrecarga de operador =
    HSV& operator=(const uint32_t color);


};
