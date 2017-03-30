#include "Trans.h"

Trans::Trans(int clave)
{
    this->clave = clave;
}

Trans::~Trans()
{
    //dtor
}
string Trans::transponer(string frase){
/*    vector<string> ono(clave);
    string finl;
    int si=frase.size();
    int a=0,r=1;
    for(int i=0;i<si;i++){
        ono[a] +=frase[i];
        if(a == (clave-1))
            r=-1;
        else if(a== 0)
            r = 1;
        a+=r;
        }
    for(int i=0;i<clave;i++)
        finl+=ono[i];
    return finl;
*/
    string tay;
    int d=0,siz=frase.size(),r=clave,u=clave-3;
    int aux=siz;
    for(int i=0;i<siz;i++){
        if(d>=aux){
            d=0;
            r--;
            aux--;}
        d+=clave-r;


        tay+=frase[d];
        if (aux<siz)
            if(aux>(siz-(clave-1))){
                if(u/-1 == 1)
                    ;
                else
                    u*=-1;
                    d++;}
        d+=u;
        d+=r+(r-3);
        }
    return tay;
    }

string Trans::poner(string tra){
    string a = tra;
    return a;
}
