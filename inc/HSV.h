#ifndef HSV_H
#define HSV_H
class HSV {
  public:
    float h;
    float s;
    float v;
    HSV(){}
    HSV(float h,float s, float v){
      this->h = h;
      this->s = s;
      this->v = v;
    };
    HSV(const HSV &otro){
      this->h = otro.h;
      this->s = otro.s;
      this->v = otro.v;
    };
    HSV operator=(const HSV &otro){
      this->h = otro.h;
      this->s = otro.s;
      this->v = otro.v;
      return *this;
    }
};
#endif
