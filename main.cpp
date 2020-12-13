#include "bala.h"
void GenerarDisparo(Bala B_, int x_, int y_);
int main()
{
    float Ho, Hd, d;
    int menu, cont=0;
    bool resp=false;
    cout<<"Digite la altura del canion ofensivo: "<<endl; cin>>Ho;
    cout<<"Digite la altura del canion defensivo: "<<endl; cin>>Hd;
    cout<<"Digite la distancia que sepra los caniones: "<<endl;cin>>d;
    Bala Bo(0.05*d,0,Ho,1);
    Bala Bd(0.025*d,d,Hd,-1);
    Bala Bn(0.005*d,0,Ho,1);
    cout<<"(1) Generar 3 disparos ofensivos que comprometan la integridad del canion defensivo."<<endl;
    cout<<"(2) Generar 3 disparos defensivos que comprometan la integridad del canion ofensivo."<<endl;
    cin>>menu;
    switch(menu){
        case 1:
            GenerarDisparo(Bo,d,Hd);
        /*
            while(cont<3){
                Bo.AnguloAleatorio();
                for(int v0 = 0;v0<100;v0+=2){
                    Bo.VelocidadX(Bo.angulo,v0);
                    Bo.VelocidadY(Bo.angulo,v0);
                    for(int t=0;t<=20;t++){
                        Bo.PosicionX(t);
                        Bo.PosicionY(t);
                        if(sqrt(pow(Bo.x-d,2)+pow(Bo.y-Hd,2))<=Bo.radio){
                            cout<<"angulo de riezgo "<<Bo.angulo*180/Bo.pi<<" y velocidad: "<<v0<<"Tiempo de vuelo: "<<t<<endl;
                            cont++;
                            resp=true;
                            break;
                        }
                    }
                    if(resp==true) {resp=false; break;}
                }
            }*/
        break;

        case 2:
            GenerarDisparo(Bd,0,Ho);
        break;
    }

    return 0;
}

void GenerarDisparo(Bala B_, int x, int y){
    Bala B=B_;
    int cont=0;
    bool resp=false;
    while(cont<3){
        B.AnguloAleatorio();
        for(int v0 = 0;v0<100;v0+=2){
            B.VelocidadX(B.angulo,v0);
            B.VelocidadY(B.angulo,v0);
            for(int t=0;t<=20;t++){
                B.PosicionX(t);
                B.PosicionY(t);
                if(sqrt(pow(B.x-x,2)+pow(B.y-y,2))<=B.radio){
                    cout<<"angulo de riezgo "<<B.angulo*180/B.pi<<" y velocidad: "<<v0<<"Tiempo de vuelo: "<<t<<endl;
                    cont++;
                    resp=true;
                    break;
                }
            }
            if(resp==true) {resp=false; break;}
        }
    }
}
