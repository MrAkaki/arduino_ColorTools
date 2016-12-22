#include "HSV.h"


HSV::HSV():h(0),s(0),v(0){}

HSV::HSV(float h,float s, float v){
  this->h = h;
  this->s = s;
  this->v = v;
};


HSV::HSV(const HSV &otro){
  this->h = otro.h;
  this->s = otro.s;
  this->v = otro.v;
};

/**
 * Transforma del modelo de color HSV al modelo de color RGB.
 * @param HSV &input, entrada HSV a tranformar.
 * @param RGB *responce, salida RGB tranformado.
 **/
void HSV::toRGB(RGB& otro){
  float f,p,q,t,hh=this->h,sh=this->s,vh=this->v;
  int i;
  if(sh == 0) { // Achromatico (gris)
    otro.r = otro.g = otro.b = round(vh*255);
    return;
  }
  hh /= 60; // sector 0 to 5
  i = floor(hh);
  f = hh - i; // parte decimal de  h
  p = vh * (1 - sh);
  q = vh * (1 - sh * f);
  t = vh * (1 - sh * (1 - f));
  switch(i) {
    case 0:
      otro.r = round(255*vh);
      otro.g = round(255*t);
      otro.b = round(255*p);
      break;
    case 1:
      otro.r = round(255*q);
      otro.g = round(255*vh);
      otro.b = round(255*p);
      break;
    case 2:
      otro.r = round(255*p);
      otro.g = round(255*vh);
      otro.b = round(255*t);
      break;
    case 3:
      otro.r = round(255*p);
      otro.g = round(255*q);
      otro.b = round(255*vh);
      break;
    case 4:
      otro.r = round(255*t);
      otro.g = round(255*p);
      otro.b = round(255*vh);
      break;
    default: // case 5:
      otro.r = round(255*vh);
      otro.g = round(255*p);
      otro.b = round(255*q);
    }
}
//Sobrecarga de operador =
HSV& HSV::operator=(const HSV &otro){
  this->h = otro.h;
  this->s = otro.s;
  this->v = otro.v;
  return *this;
}
HSV& HSV::operator=(const RGB &otro){
  otro.toHSV(*this);
  return *this;
}

HSV& HSV::operator=(const uint32_t color){
  uint8_t r = color >> 16, g = color >>  8, b = color;
  RGB rgb(r,g,b);
  rgb.toHSV(*this);
  return *this;
}
