#ifndef BALA_H
#define BALA_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Bala
{

public:
    Bala(int radio_, float x0_, float y0_, int aux_);
    float angulo, pi=3.14159265, x, y, vx, vy, x0, y0, radio, g=9.81, aux;
    void AnguloAleatorio();
    void VelocidadX(float angle_, int Vo_);
    void VelocidadY(float angle_, int Vo_);
    void PosicionX(int time);
    void PosicionY(int time);
};

#endif // BALA_H
