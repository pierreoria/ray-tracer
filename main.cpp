#include <algorithm>
#include <complex>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "src/Camera.cpp"
#include "src/Plane.cpp"
#include "src/Vector.cpp"
#include "src/Sphere.cpp"
#include "src/Triangle.cpp"
#include "src/ObjReader.cpp"
#include "src/Mesh.cpp"
#include "src/Colormap.cpp"
#include "src/Transformations.cpp"
#include "src/Texture.cpp"

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    //-------------

// Create a marble texture
marble_texture* marbleTex = new marble_texture(5.0); // scale = 5.0

// Set the texture of the sphere
sphere->setTexture(marbleTex);

// Add the sphere to your scene
objetos.push_back(sphere);


    // ----------













    point pos_cam(6,2,0);
    point target_cam(0,0,0);
    vetor up_cam(0,1,0);

    camera cam(400, pos_cam, target_cam, up_cam, 16.0/9.0, 1.0);

    // point origem_esfera1(1,0,2);
    point origem_esfera1(4,1,2);    
    point origem_esfera2(0,0.2,0);    
    point origem_esfera3(1.5,-0.5,-2);

    // vetor normal_plano(0,1,0);

    vetor cor(1,0,0);
    vetor cor2(0.4,0.4,0.4);
    vetor cor3(0,0,0.5);
    vetor kd = vetor(0.5, 0, 0);
    vetor ks = vetor(1, 0, 0);
    vetor ke = vetor(0.000000, 0.000000, 0.000000);
    vetor ka = vetor(0.6, 1, 1);
    double ns = 10.000000;
    vetor k_esfera = vetor(0,0,0);
    //vector <object*> triangulos;
    vector<object*> triangulos = reader.getTriangles();

    rotacao(triangulos, 50.0, 'y');

    sphere esfera1 = sphere(origem_esfera2, 3, vetor(0,0,0), kd,k_esfera,ke,k_esfera, ns, 1.0, 0.0);
    triangulos.push_back(&esfera1);
    sphere esfera2 = sphere(origem_esfera2, 0.5, cor, kd,ks,ke,ka, ns, 0.0, 0.0);
    triangulos.push_back(&esfera2);
    sphere esfera3 = sphere(origem_esfera1,0.5, vetor(0,0,0.5), kd,ks,ke,ka, ns, 0.0, 1.0);
    // triangulos.push_back(&esfera3);
    // sphere esfera4 = sphere(origem_esfera2, 0.5, cor3, kd,ks,ke,ka, ns, 0.0, 0.0);
    // triangulos.push_back(&esfera4);

    // sphere esfera3 = sphere(origem_esfera3, 1, cor3, kd,ks,ke,ka, ns, ni, 0.0);
    // triangulos.push_back(&esfera3);
    // rotacao(triangulos, 45.0, 'X');
    // rotacao(triangulos, 45.0, 'Y');
    // rotacao(triangulos, 45.0, 'Z');
    // translacao(triangulos, 0, 3, 0);

    point origem_plano(0,-4,0);
    vetor ka_plano = vetor(0,0,0);
    vetor cor_plano(0.,0.5,0);
    plane plano = plane(origem_plano, vetor(0, 1, 0), cor_plano, kd,ks,ke,ka_plano, ns, 0.0, 1.0);
    triangulos.push_back(&plano);

    vector<light> lts;
    point lt_pos(7, 3, 2);
    point lt_pos2(0, 100, -100);
    vetor lt_color(0.4,0.4,0.4);
    light lt(lt_pos,lt_color);
    light lt2(lt_pos2, lt_color);
    lts.push_back(lt);
    // lts.push_back(lt2);

    vetor ambiente_color(0.1,0.1,0.1);
    cam.render(triangulos, lts, ambiente_color);

    return 0;
}
