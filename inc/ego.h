#ifndef EGO_H
#define EGO_H
#include <vector>
#include <cstdint>
#include <string>

namespace UltraSonicSensorsDistance {

class Ego {
    public:
        Ego(float x,float y,float z,float h,float p,float r):
        x(x),y(y),z(z),h(h),p(p),r(r) {};

        float x ;
        float y ;
        float z ;
        float h ;
        float p ;
        float r ;
};

}

#endif
