#ifndef BALA_H
#define BALA_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Bala
{

public:
    Bala(int radio_, float x0_, float y0_);
    float angulo, pi=3.14159265, x, y, vx, vy, x0, y0, radio, g=9.81;
    float AnguloAleatorio();
    float VelocidadX(float angle_, int Vo_);
    float VelocidadY(float angle_, int Vo_);
    float PosicionX(int time);
    float PosicionY(int time);
};

#endif // BALA_H
