#include "RGB.h"

RGB::RGB():r(0),g(0),b(0){}

RGB::RGB(uint8_t& r,uint8_t& g, uint8_t& b){
  this->r = r;
  this->g = g;
  this->b = b;
}

RGB::RGB(const RGB &otro){
  this->r = otro.r;
  this->g = otro.g;
  this->b = otro.b;
};

void RGB::toHSV(HSV& otro){
  float r = this->r/255. , g=this->g/255. , b=this->b/255.;
  float cMax = max(max(r, g), b);
  float cMin = min(min(r, g), b);
  float delta = cMax - cMin;

  if(delta > 0) {
    if(cMax == r) {
      otro.h = 60 * (fmod(((g - b) / delta), 6));
    } else if(cMax == g) {
      otro.h = 60 * (((b - r) / delta) + 2);
    } else if(cMax == b) {
      otro.h = 60 * (((r - g) / delta) + 4);
    }

    if(cMax > 0) {
      otro.s = delta / cMax;
    } else {
      otro.s = 0;
    }

    otro.v = cMax;
  } else {
    otro.h = 0;
    otro.s = 0;
    otro.v = cMax;
  }

  if(otro.h < 0) {
    otro.h = 360 + otro.h;
  }
}

RGB& RGB::operator=(const RGB &otro){
  this->r = otro.r;
  this->g = otro.g;
  this->b = otro.b;
  return *this;
}

RGB& RGB::operator=(const HSV &otro){
  otro.toRGB(*this);
  return *this;
}

RGB& RGB::operator=(const uint32_t color){
  this->r = color >> 16;
  this->g = color >>  8;
  this->b = color;
  return *this;
}
