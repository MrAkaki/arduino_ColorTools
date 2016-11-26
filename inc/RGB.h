#ifndef RGB_H
#define RGB_H
#include "HSV.h"
class RGB {
  public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    RGB(){}
    RGB(uint8_t r,uint8_t g, uint8_t b){
      this->r = r;
      this->g = g;
      this->b = b;
    }
    RGB(const RGB &otro){
      this->r = otro.r;
      this->g = otro.g;
      this->b = otro.b;
    };
    RGB& operator=(const RGB &otro){
      this->r = otro.r;
      this->g = otro.g;
      this->b = otro.b;
      return *this;
    }
};
#endif
