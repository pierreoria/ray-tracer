#ifndef OBJECTHEADER
#define OBJECTHEADER

#include "Point.cpp"
#include "Vector.cpp"
#include "Ray.cpp"
#include "Texture.cpp"

class object {
protected:
    vetor color;
    texture* obj_texture;

public:
    // Construtor
    object(){};
    object(const vetor& color){
        this->color = color;
        this->obj_texture = nullptr;
    }

    bool hasTexture() const {
        return obj_texture != nullptr;
    }

    void setTexture(texture* tex) {
        obj_texture = tex;
    }

    vetor getTextureColor(float u, float v, vetor& p) const {
        if (obj_texture) {
            return obj_texture->value(u, v, p);
        } else {
            return getColor(); // Fallback to base color if no texture
        }
    }


    virtual vetor getKd() = 0;
    virtual  vetor getKs() = 0;
    virtual vetor getKe() = 0;
    virtual vetor getKa() = 0;
    virtual double getNi() = 0;
    virtual double getD() = 0;
    virtual double getShininess() = 0;
    vetor getColor() const { return color; }
    void setColor(const vetor& color) { this->color = color; }

    
    virtual point getPonto() = 0;
    virtual vetor getNormal() = 0;
    virtual double intersect(ray &r) = 0;
    virtual void rotacao(double angle, char eixo, point centroide) = 0;
    virtual void translacao(double dx, double dy, double dz) = 0;
    virtual void cisalhamento(double shXY, double shXZ, double shYX, double shYZ, double shZX, double shZY) = 0;
    


    virtual ~object() {}
};

#endif
