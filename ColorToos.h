#include <math.h>
#ifndef COLOR_TOOLS_H
#define COLOR_TOOLS_H

typedef struct {
    uint8_t r;       // ∈ [0, 255]
    unit8_t g;       // ∈ [0, 255]
    uint8_t b;       // ∈ [0, 255]
} RGB;

typedef struct {
    float_t h;       // ∈ [0, 360]
    float_t s;       // ∈ [0, 1]
    float_t v;       // ∈ [0, 1]
} HSV;

RGB HSV2RGB(HSV input){
  RGB responce;
  float f,p,q,t;
  int i;

  h = max(0.0, min(360., h));
  s = max(0.0, min(1., s));
  v = max(0.0, min(1., v));

  if(s == 0) { // Achromatico (gris)
    respnce.r = responce.g = responce.b = round(v*255);
    return;
  }

  h /= 60; // sector 0 to 5
  i = floor(h);
  f = h - i; // parte decimal de  h
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  switch(i) {
    case 0:
      responce.r = round(255*v);
      responce.g = round(255*t);
      responce.b = round(255*p);
      break;
    case 1:
      responce.r = round(255*q);
      responce.g = round(255*v);
      responce.b = round(255*p);
      break;
    case 2:
      responce.r = round(255*p);
      responce.g = round(255*v);
      responce.b = round(255*t);
      break;
    case 3:
      responce.r = round(255*p);
      responce.g = round(255*q);
      responce.b = round(255*v);
      break;
    case 4:
      responce.r = round(255*t);
      responce.g = round(255*p);
      responce.b = round(255*v);
      break;
    default: // case 5:
      responce.r = round(255*v);
      responce.g = round(255*p);
      responce.b = round(255*q);
    }
    return responce;
}

HSV RGB2HSV(RGB input) {
  HSV responce;
  float r = input.r/255. , g=input.g/255. , b=input.b/255.;
  float cMax = max(max(r, g), b);
  float cMin = min(min(r, g), b);
  float delta = cMax - cMin;

  if(delta > 0) {
    if(cMax == r) {
      responce.h = 60 * (fmod(((g - b) / delta), 6));
    } else if(cMax == g) {
      responce.h = 60 * (((b - r) / delta) + 2);
    } else if(cMax == b) {
      responce.h = 60 * (((r - g) / delta) + 4);
    }

    if(cMax > 0) {
      responce.s = delta / cMax;
    } else {
      responce.s = 0;
    }

    responce.v = cMax;
  } else {
    responce.h = 0;
    responce.s = 0;
    responce.v = cMax;
  }

  if(responce.h < 0) {
    responce.h = 360 + responce.h;
  }
}

#endif
