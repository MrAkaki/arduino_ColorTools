#ifndef HSV_H
#define HSV_H

/**
* Clase para modelo de color HSV
* @author Alex Vargas Benamburg
* @email alex@vbalex.com
* @license CC-BY-SA
**/
class HSV {
  public:
    // variable para Hue, tono
    float h;
    // variable para Saturation, saturacion
    float s;
    // variable para Value, valor
    float v;

    //Constructor por defecto
    HSV(){}

    //Constructor con parametros
    HSV(float h,float s, float v){
      this->h = h;
      this->s = s;
      this->v = v;
    };

    //Contructor de copia
    HSV(const HSV &otro){
      this->h = otro.h;
      this->s = otro.s;
      this->v = otro.v;
    };
    
    //Sobrecarga de operador =
    HSV operator=(const HSV &otro){
      this->h = otro.h;
      this->s = otro.s;
      this->v = otro.v;
      return *this;
    }
};
#endif
