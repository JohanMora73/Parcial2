#include "bala.h"

int main()
{
    float Ho, Hd, d;
    cout<<"Digite la altura del canion ofensivo: "<<endl; cin>>Ho;
    cout<<"Digite la altura del canion defensivo: "<<endl; cin>>Hd;
    cout<<"Digite la distancia que sepra los caniones: "<<endl;cin>>d;
    Bala Bo(0.05*d,0,Ho);
    Bala Bd(0.025*d,d,Hd);
    Bala Bn(0.005*d,0,Ho);
    return 0;
}
