#ifndef TEXTURE
#define TEXTURE

#include <iostream>
#include <tuple>
#include <vector>
#include "Point.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"
#include "Triangle.cpp"
#include "Light.cpp"
#include "Perlin.cpp"


class marble_texture : public texture {
    public:
    perlin noise;
    float scale;
    marble_texture() {}
    marble_texture(double x) {scale = x;}
    virtual vetor value(double u, double v,vetor& p) const{
        return vetor(1,1,1)*0.5*(1 + sin(scale*p.getZ() + 10.0 * noise.turb(p))); 
    }
}


#endif
