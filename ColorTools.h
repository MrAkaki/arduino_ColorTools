
#ifndef COLOR_TOOLS_H
#define COLOR_TOOLS_H

#include "inc/RGB.h"
#include "inc/HSV.h"
#include <math.h>


/**
 * Transforma del modelo de color HSV al modelo de color RGB.
 * @param HSV &input, entrada HSV a tranformar.
 * @param RGB *responce, salida RGB tranformado.
 **/

void HSV2RGB(HSV &input, RGB *responce){
  float f,p,q,t;
  int i;

  input.h = max(0.0, min(360., input.h));
  input.s = max(0.0, min(1., input.s));
  input.v = max(0.0, min(1., input.v));

  if(input.s == 0) { // Achromatico (gris)
    responce->r = responce->g = responce->b = round(input.v*255);
    return;
  }

  input.h /= 60; // sector 0 to 5
  i = floor(input.h);
  f = input.h - i; // parte decimal de  h
  p = input.v * (1 - input.s);
  q = input.v * (1 - input.s * f);
  t = input.v * (1 - input.s * (1 - f));
  switch(i) {
    case 0:
      responce->r = round(255*input.v);
      responce->g = round(255*t);
      responce->b = round(255*p);
      break;
    case 1:
      responce->r = round(255*q);
      responce->g = round(255*input.v);
      responce->b = round(255*p);
      break;
    case 2:
      responce->r = round(255*p);
      responce->g = round(255*input.v);
      responce->b = round(255*t);
      break;
    case 3:
      responce->r = round(255*p);
      responce->g = round(255*q);
      responce->b = round(255*input.v);
      break;
    case 4:
      responce->r = round(255*t);
      responce->g = round(255*p);
      responce->b = round(255*input.v);
      break;
    default: // case 5:
      responce->r = round(255*input.v);
      responce->g = round(255*p);
      responce->b = round(255*q);
    }
}

/**
 * Transforma del modelo de color RGB al modelo de color HSV.
 * @param RGB &input, entrada RGB a tranformar.
 * @param HSV *responce, salida HSV tranformado.
 **/
void RGB2HSV(RGB input, HSV *responce) {
  float r = input.r/255. , g=input.g/255. , b=input.b/255.;
  float cMax = max(max(r, g), b);
  float cMin = min(min(r, g), b);
  float delta = cMax - cMin;

  if(delta > 0) {
    if(cMax == r) {
      responce->h = 60 * (fmod(((g - b) / delta), 6));
    } else if(cMax == g) {
      responce->h = 60 * (((b - r) / delta) + 2);
    } else if(cMax == b) {
      responce->h = 60 * (((r - g) / delta) + 4);
    }

    if(cMax > 0) {
      responce->s = delta / cMax;
    } else {
      responce->s = 0;
    }

    responce->v = cMax;
  } else {
    responce->h = 0;
    responce->s = 0;
    responce->v = cMax;
  }

  if(responce->h < 0) {
    responce->h = 360 + responce->h;
  }
}

#endif
