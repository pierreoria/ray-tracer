#ifndef PERLIN
#define PERLIN

#include <iostream>
#include <tuple>
#include <vector>
#include "Point.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"
#include "Triangle.cpp"
#include "Light.cpp"
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>

class perlin {
    public:
        float noise(vetor& p) {
            float u = p.getX()() - floor(p.getX()());
            float v = p.getY()() - floor(p.getY()());
            float w = p.getZ()() - floor(p.getZ()());
            int i = floor(p.getX()());
            int j = floor(p.getY()());
            int k = floor(p.getZ()());
            vetor c[2][2][2];
            for (int di=0; di < 2; di++)
                for (int dj=0; dj < 2; dj++)
                    for (int dk=0; dk < 2; dk++)
                        c[di][dj][dk] = ranvec[perm_x[(i+di) & 255] ^
                                                perm_y[(j+dj) & 255] ^
                                                perm_z[(k+dk) & 255]];
            return perlin_interp(c, u, v, w);
        }

        inline float perlin_interp(vetor c[2][2][2], float u, float v, float w) {
            float uu = u*u*(3-2*u);
            float vv = v*v*(3-2*v);
            float ww = w*w*(3-2*w);
            float accum = 0;
            for (int i=0; i < 2; i++)
                for (int j=0; j < 2; j++)
                    for (int k=0; k < 2; k++) {
                        vetor weight_v(u-i, v-j, w-k);
                        accum += (i*uu + (1-i)*(1-uu)) *
                                (j*vv + (1-j)*(1-vv)) *
                                (k*ww + (1-k)*(1-ww)) * dot(c[i][j][k], weight_v);
                    }
            return accum;
        }

        double turb(const vetor& p, int d = 7) {
            double accum = 0;
            vetor tmp = p;
            double wei = 1;
            for (int i = 0; i < d; i++){
                accum += wei*noise(tmp);
                wei /= 2.0;
                tmp = 2.0 * tmp;
            }
            return fabs(accum);
        }
                static vetor *ranvec;
                static int *perm_x;
                static int *perm_y;
                static int *perm_z;



};








#endif
