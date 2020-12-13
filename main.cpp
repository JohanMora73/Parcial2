#include "bala.h"
void GenerarDisparos(Bala B_, int x_, int y_);
void GenerarDispDefensivos(Bala B1,Bala B2,float d, float Hd, float Ho, int caso, int n);
void GenerarDispNeutralizador(Bala B1, Bala B2, Bala B3, float d, float Hd);
int main()
{
    float Ho, Hd, d, a, vo;
    int menu;
    cout<<"Digite la altura del canion ofensivo: "<<endl; cin>>Ho;
    cout<<"Digite la altura del canion defensivo: "<<endl; cin>>Hd;
    cout<<"Digite la distancia que sepra los caniones: "<<endl;cin>>d;
    Bala Bo(0.05*d,0,Ho,1);
    Bala Bd(0.025*d,d,Hd,-1);
    Bala Bn(0.005*d,0,Ho,1);
    cout<<"(1) Generar 3 disparos ofensivos que comprometan la integridad del canion defensivo."<<endl;
    cout<<"(2) Generar 3 disparos defensivos que comprometan la integridad del canion ofensivo."<<endl;
    cout<<"(3) Dado un disparo ofensivo, generar 3 disparos defensivos que impida que el canion defensivo sea destruido sin importar si el canion ofensivo pueda ser destruido."<<endl;
    cout<<"(4) Dado un disparo ofensivo, generar 3 disparos defensivos que impidan que los caniones defensivo y ofensivo puedan ser destruidos."<<endl;
    cout<<"(5) Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la efectividad del ataque ofensivo, generar 3 disparos que neutralicen el ataque defensivo y permitan que el ataque ofensivo sea efectivo."<<endl;
    cin>>menu;
    switch(menu){
        case 1:
            GenerarDisparos(Bo,d,Hd);
        break;

        case 2:
            GenerarDisparos(Bd,0,Ho);
            cout<<":) angulo defensivo: "<<Bd.angulo*180/Bd.pi<<" Velocidad inicial defensiva: "<<Bd.vx/cos(Bd.angulo)<<endl<<"Angulo ofensivo: "<<Bo.angulo*180/Bo.pi<<" Velocidad inicial ofensiva: "<<Bo.vx/cos(Bo.angulo)<<endl;
        break;

        case 3:
            cout<<"ingrese los datos del disparo del canion ofensivo, angulo (en grados) y velocidad inicial respectivamente: "<<endl;
            cin>>a>>vo;
            Bo.angulo=a*Bo.pi/180;
            Bo.vx=vo*cos(Bo.angulo);
            Bo.vy=vo*sin(Bo.angulo);
            GenerarDispDefensivos(Bo,Bd,d, Hd, Ho, 1, 3);
        break;

        case 4:
            cout<<"ingrese los datos del disparo del canion ofensivo, angulo (en grados) y velocidad inicial respectivamente: "<<endl;
            cin>>a>>vo;
            Bo.angulo=a*Bo.pi/180;
            Bo.vx=vo*cos(Bo.angulo);
            Bo.vy=vo*sin(Bo.angulo);
            GenerarDispDefensivos(Bo,Bd,d, Hd, Ho, 2, 3);

        break;

        case 5:
            cout<<"ingrese los datos del disparo del canion ofensivo, angulo (en grados) y velocidad inicial respectivamente: "<<endl;
            cin>>a>>vo;
            Bo.angulo=a*Bo.pi/180;
            Bo.vx=vo*cos(Bo.angulo);
            Bo.vy=vo*sin(Bo.angulo);
            GenerarDispDefensivos(Bo,Bd,d, Hd, Ho, 1, 1);
            //cout<<":) angulo defensivo: "<<Bd.angulo*180/Bd.pi<<" Velocidad inicial defensiva: "<<Bd.vx/cos(Bd.angulo)<<endl<<"Angulo ofensivo: "<<Bo.angulo*180/Bo.pi<<" Velocidad inicial ofensiva: "<<Bo.vx/cos(Bo.angulo)<<endl;
            GenerarDispNeutralizador(Bo, Bd, Bn, d, Hd);
        break;
    }

    return 0;
}

void GenerarDisparos(Bala B, int x, int y){
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
                    cout<<"angulo de riezgo: "<<B.angulo*180/B.pi<<" Velocidad inicial: "<<v0<<" Tiempo de vuelo: "<<t<<" Coordenada final x: "<<B.x<<" Coordenada final y: "<<B.y<<endl;
                    cont++;
                    resp=true;
                    break;
                }
            }
            if(resp==true) {resp=false; break;}
        }
    }
}

void GenerarDispDefensivos(Bala Bo,Bala Bd, float d, float Hd, float Ho, int caso, int n){
    bool riezgo,resp;
    int cont=0;
    for(int t=0;t<30;t++){
        Bo.PosicionX(t);
        Bo.PosicionY(t);
        if(sqrt(pow(Bo.x-d,2)+pow(Bo.y-Hd,2))<=Bo.radio){
            riezgo=true;
            break;
        }
        else riezgo=false;
    }
    if(riezgo==true){
        cout<<"El disparo representa un riezgo"<<endl;
        while(cont<n){
            Bd.AnguloAleatorio();
            for(int vo = 0;vo<100;vo+=2){
                Bd.VelocidadX(Bd.angulo,vo);
                Bd.VelocidadY(Bd.angulo,vo);
                for(int t=0;t<30;t++){
                    Bo.PosicionX(t+2);
                    Bo.PosicionY(t+2);
                    Bd.PosicionX(t);
                    Bd.PosicionY(t);
                    if(sqrt(pow(Bo.x-Bd.x,2)+pow(Bo.y-Bd.y,2))<=Bd.radio && sqrt(pow(Bo.x-d,2)+pow(Bo.y-Hd,2))>Bo.radio){
                        if(caso==1){
                            cout<<"Un disparo defensivo ceretero es: angulo"<<Bd.angulo*180/Bd.pi<<", velovidad: "<<-Bd.vx/cos(Bd.angulo)<<" tiempo de vuelo: "<<t<<" Coordenada final x: "<<Bd.x<<" Coordenada final y: "<<Bd.y<<endl;
                            cont++;
                            resp=true;
                            break;
                        }
                        else{
                            if(sqrt(pow(Bo.x-0,2)+pow(Bo.y-Ho,2))>Bo.radio){
                                cout<<"Un disparo defensivo ceretero es: angulo"<<Bd.angulo*180/Bd.pi<<", velovidad: "<<-Bd.vx/cos(Bd.angulo)<<" tiempo de vuelo: "<<t<<" Coordenada final x: "<<Bd.x<<" Coordenada final y: "<<Bd.y<<endl;
                                cont++;
                                resp=true;
                                break;
                            }
                        }
                    }
                }
                if(resp==true) {resp=false; break;}
            }
        }
    }
    else cout<<"El disparo no representa riezgos"<<endl;
}

void GenerarDispNeutralizador(Bala Bo, Bala Bd, Bala Bn, float d, float Hd){
    int cont=0;
    bool resp,riezgo;
    for(int t=0;t<30;t++){
        Bo.PosicionX(t);
        Bo.PosicionY(t);
        if(sqrt(pow(Bo.x-d,2)+pow(Bo.y-Hd,2))<=Bo.radio){
            riezgo=true;
            break;
        }
        else riezgo=false;
    }
    if(riezgo==true){
        cout<<"El disparo representa un riezgo"<<endl;
        Bd.AnguloAleatorio();
        for(int vo = 0;vo<100;vo+=2){
            Bd.VelocidadX(Bd.angulo,vo);
            Bd.VelocidadY(Bd.angulo,vo);
            for(int t=0;t<30;t++){
                Bo.PosicionX(t+2);
                Bo.PosicionY(t+2);
                Bd.PosicionX(t);
                Bd.PosicionY(t);
                if(sqrt(pow(Bo.x-Bd.x,2)+pow(Bo.y-Bd.y,2))<=Bd.radio && sqrt(pow(Bo.x-d,2)+pow(Bo.y-Hd,2))>Bo.radio){
                    cout<<"Un disparo defensivo ceretero es: angulo"<<Bd.angulo*180/Bd.pi<<", velovidad: "<<-Bd.vx/cos(Bd.angulo)<<" tiempo de vuelo: "<<t<<" Coordenada final x: "<<Bd.x<<" Coordenada final y: "<<Bd.y<<endl;
                    resp=true;
                    break;
                }
            }
            if(resp==true) {resp=false; break;}
        }
    }
    if(riezgo==true){
        while(cont<3){
            Bn.AnguloAleatorio();
            cout<<"angulo defensivo: "<<Bd.angulo*180/Bd.pi<<" Velocidad inicial defensiva: "<<Bd.vx/cos(Bd.angulo)<<endl<<"Angulo ofensivo: "<<Bo.angulo*180/Bo.pi<<" Velocidad inicial ofensiva: "<<Bo.vx/cos(Bo.angulo)<<endl;
            for(int vo=0 ;vo<=100;vo+=2){
                Bn.VelocidadX(Bn.angulo,vo);
                Bn.VelocidadY(Bn.angulo,vo);
                for(int t=0;t<30;t++){
                    Bo.PosicionX(t+3);
                    Bo.PosicionY(t+3);
                    Bd.PosicionX(t+1);
                    Bd.PosicionY(t+1);
                    Bn.PosicionX(t);
                    Bn.PosicionY(t);
                    if(sqrt(pow(Bo.x-Bd.x,2)+pow(Bo.y-Bd.y,2))>Bd.radio && sqrt(pow(Bd.x-Bn.x,2)+pow(Bd.y-Bn.y,2))<=Bn.radio && sqrt(pow(Bn.x-d,2)+pow(Bn.y-Hd,2))>Bn.radio){
                        cout<<"Un disparo certero para neutralizar es: "<<" Angulo: "<<Bn.angulo*180/Bn.pi<<" Vo: "<<Bn.vx/cos(Bn.angulo)<<" Tiempo de vuelo: "<<t<<" Coordenada en x: "<<Bn.x<<"Coordenada en y"<<Bn.y<<endl;
                        cout<<"Datos del disparo defensivo: defensivo: "<<" Angulo: "<<Bd.angulo*180/Bd.pi<<" Vo: "<<Bd.vx/cos(Bd.angulo)<<" Tiempo de vuelo: "<<t+1<<" Coordenada en x: "<<Bd.x<<" Coordenada en y: "<<Bd.y<<endl;
                        cout<<"Datos del disparo ofensivo: defensivo: "<<" Angulo: "<<Bo.angulo*180/Bo.pi<<" Vo: "<<Bo.vx/cos(Bo.angulo)<<" Tiempo de vuelo: "<<t+3<<" Coordenada en x: "<<Bo.x<<" Coordenada en y: "<<Bo.y<<endl;
                        cont++;
                        resp=true;
                        break;
                    }
                }
                if(resp==true) {resp=false; break;}
            }
        }
    }

}
