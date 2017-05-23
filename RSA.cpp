#include "RSA.h"
#include <math.h>

RSA::RSA(int bits){
    Generar_claves(bits);
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
}
RSA::RSA(ZZ publica, ZZ n){
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    e=publica;
    N=n;
}
RSA::~RSA(){}

ZZ RSA::exponenciacion(ZZ base,ZZ exp){
    ZZ R=to_ZZ(1);
    while(exp > 0){
        if(modulo(exp,to_ZZ(2))==1)
            R=modulo(R*base,this->N);
        base = modulo(base*base,this->N);
        exp = exp/2;
    }
    return R;
}
long RSA::euclides(ZZ a,ZZ b){///a >= b
    long mcd=1;
    ZZ t;
    while(modulo(a,to_ZZ(2))==0 && modulo(b,to_ZZ(2))==0){
        a=a/2;
        b=b/2;
        mcd = mcd*2;
    }
    while(a != 0){
        while(modulo(a,to_ZZ(2))==0){a=a/2;}
        while(modulo(b,to_ZZ(2))==0){b=b/2;}
        t=valorAb(a-b)/2;
        if(a >= b)
            a = t;
        else
            b = t;
    }
    return(mcd * to_int(b));
}
void RSA::Generar_claves(int bs){
        int ss=bs/2;
        int pp=sqrt(bs);
        p = ga(ss,bs,pp,13);
        q = ga(ss,bs,pp,14);
        while(ProbPrime(p,10)!=1)///while(test_primalidad(p)==false)///
        {
            p = ga(ss,bs,pp,13);
        }
        while(ProbPrime(q,10)!=1)///while(test_primalidad(q)==false)///
        {
            q = ga(ss,bs,pp,14);
        }
        this->N= p * q;
        ZZ phi_N = (p - 1) * (q - 1);
       // ZZ C=phi_N;
        e = ga(ss,bs,pp,15);
        while(e > phi_N || euclides(e, phi_N) != 1)
        {
            e = ga(ss,bs,pp,15);
        }
        cout <<"Clave publica: " << e << endl;
        d = modulo(inversa(e, phi_N),phi_N);
        cout << "Clave privada: " << d << endl;
        cout <<"N: " << N << endl;
}
bool RSA::test_primalidad(ZZ x){
    ZZ a = modulo(ga(10,16,4,7),x-2)+1;
    if(potenciaMod(a,x-1,x)==1)
        return true;
    else
        return false;
}
ZZ RSA::inversa(ZZ E,ZZ n){
    ZZ n0 = n, temp, q;
    ZZ E0 = to_ZZ(0);
    ZZ E1 = to_ZZ(1);
    while (E > 1){
        q = E / n;
        temp = n;
        n = modulo(E,n);
        E = temp;
        temp = E0;
        E0 = E1 - q * E0;
        E1 = temp;
    }
    if (E1 < 0)
        E1 += n0;
    return E1;
}
vector<ZZ> RSA::extendido_euclides(ZZ a,ZZ b){
    vector<ZZ> r;
    r.push_back(to_ZZ(euclides(a,b)));
    if(r[0]==1){
        r.push_back(inversa(a,b));
        r.push_back(inversa(b,a));
    }
    return r;
}
vector<ZZ> RSA::encriptar(string mensaje){
        vector<ZZ> message;
        ZZ pos;
        for(int i = 0; i <= mensaje.size()-1; i++){
            pos=to_ZZ(alfabeto.find(mensaje[i]));
            pos=exponenciacion(pos,e);
            message.push_back(pos);
            cout<<message[i]<<" , ";
        }
        cout<<endl;
        return message;
}
string RSA::desencriptar(vector<ZZ> mensaje,ZZ priv,ZZ n){
        string message;
        ZZ pos;
      //  int p;
        for(int i = 0; i < mensaje.size(); i++){
            pos=mensaje[i];
            pos=exponenciacion(pos,this->d);
           // pos=potenciaMod(pos,priv,n);
            message +=alfabeto[to_int(pos)];
        }
        return message;
}
ZZ RSA::getn(){return N;}
ZZ RSA::getpp(){return e;}
ZZ RSA::geta(){return d;}
