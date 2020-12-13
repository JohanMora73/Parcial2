#include "bala.h"

Bala::Bala(int radio_, float x0_, float y0_)
{
    radio=radio_;
    x0=x0_;
    y0=y0_;
}

float Bala::AnguloAleatorio()
{
    angulo = rand () % (90-0+1) + 0;   // Este está entre M y N
    angulo*=pi/180;
    return angulo;
}

float Bala::VelocidadX(float angle_,int Vo)
{
    float angle=angle_;
    vx=Vo*cos(angle);
    return vx;
}

float Bala::VelocidadY(float angle_,int Vo)
{
    float angle=angle_;
    vy=Vo*sin(angle);
    return vy;
}

float Bala::PosicionX(int time)
{
    x=x0+vx*time;
    return x;
}

float Bala::PosicionY(int time)
{
    y=y0+vy*time-0.5*g*time*time;
    return y;
}
