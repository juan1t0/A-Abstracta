#include "ElGamal.h"

ElGamal::ElGamal(int bits){
    generarClaves(bits);
}
ElGamal::ElGamal(ZZ e_1,ZZ e_2,ZZ pp){
    this->e1 = e_1;
    this->e2 = e_2;
    this->p = pp;
}
ElGamal::~ElGamal(){}
///------------------------------------
ZZ ElGamal::getP(){return this->p;}
ZZ ElGamal::getE1(){return this->e1;}
ZZ ElGamal::getE2(){return this->e2;}
ZZ ElGamal::getD(){return this->d;}
void ElGamal::setP(ZZ pp){this->p=pp;}
void ElGamal::setE1(ZZ ee1){this->e1=ee1;}
void ElGamal::setE2(ZZ ee2){this->e2=ee2;}
void ElGamal::setD(ZZ dd){this->d=dd;}
///------------------------------------

ZZ ElGamal::raizPrimitiva(){
    ZZ q=(p-1)/2,g,dos=to_ZZ(2);
    for(int i=1;i<p-1;i++){
        g = i;
        if((potenciaMod(g,dos,p)!=1) && (potenciaMod(g,q,p)!= 1))
            return g;
    }
    return g;
}

void ElGamal::generarClaves(int bits){
    p = ga(17,bits,8,23);
    while(ProbPrime(p,10)!=1 && ProbPrime((p-1)/2,10)!=1)
        p = ga(17,bits,8,23);
    this->e1 = raizPrimitiva();
    this->d = ga(11,bits,8,21);
    //this->r = ga(11,bits,5,23);
   // cout<<"acamuere"<<endl;
    while(d <1 && d>p-2){ //)&&(r<1 && r>p-2)){
        this->d = ga(11,bits,8,21);
      //  this->r = ga(11,bits,5,23);
    }
    this->e2 = potenciaMod(e1,d,p);
    cout<<"p: "<<p<<endl;
    cout<<"e1: "<<e1<<endl;
    cout<<"e2: "<<e2<<endl;
}
string ElGamal::cifrar(string mensaje){
    string msn;
    string dig;
    ZZ Dig,C1;
    this->r = ga(11,16,4,23);
    while(r<1 && r>p-2){
        this->r = ga(11,16,4,23);
    }
    C1=potenciaMod(e1,r,p);
    Km=potenciaMod(e2,r,p);

    int pos, sizeOfMensaje = mensaje.size();
    ///PROCESAMIENTO DEL TEXTO
    for(int i=0;i<sizeOfMensaje;i++){
        pos = alfabeto.find(mensaje[i]);
        if(pos<10)
            dig+="0";
        dig+=zzToString(to_ZZ(pos));
    }
    ZZ temp = to_ZZ(dig.size());
    ZZ nless1= to_ZZ(zzToString(this->p).size() -1);
    while(modulo(temp,nless1)!= 0){
        pos = alfabeto.find("w");
        dig+=zzToString(to_ZZ(pos));
        temp=to_ZZ(dig.size());
    }
    ///----------------------------------
    string aux;
    string axe;
    int sizeOFDig=dig.size(),nm1=to_int(nless1);
    for(int i=0;i<sizeOFDig;i+=nm1){
        int j=0;
        while(j != nm1){
            aux+=dig[i+j];
            j++;
        }
        Dig = stringTozz(aux);
        Dig = modulo((Dig * Km),p);
        aux = zzToString(Dig);
        int a = aux.size();
        while(to_ZZ(a) < nless1+1){
            a++; axe += "0";
        }
        axe+=aux;
        msn+=axe;
        aux="";axe="";
    }
    string c1s = zzToString(C1);
    string cc1;
    if(c1s.size()<to_int(nless1+1)){
        cc1='0'*(to_int(nless1+1)-c1s.size());
    }
    cc1+=c1s;
    cc1 += msn;
    msn=cc1;
    return msn;///msn == C2;
}
string ElGamal::descifra_mensaje(string cifrado){
    string msn;
    string dig;
    string c1s;
    ZZ Dig,C1;
    ZZ nlen = to_ZZ(zzToString(this->p).size());
    c1s=cifrado.substr(0,to_int(nlen));
    cout<<c1s<<endl;
    cifrado = cifrado.substr(to_int(nlen));
    cout<<cifrado<<endl;
    int pos=0 , sizeOfCifrado = cifrado.size(), nlo=to_int(nlen);
    string aux;
    C1 = stringTozz(c1s);
    Km = potenciaMod(C1,d,p);
    ZZ Km_1=inversoMult(Km,p);
    for(int i=0;i<sizeOfCifrado;i+=nlo){
        int j=0;
        while(j < nlo){
            aux+=cifrado[j+i];
            j++;
        }
        Dig = stringTozz(aux);
        Dig = modulo(Dig*Km_1,p);
        aux = zzToString(Dig);
        int a=aux.size();
        while(a<nlo-1){
            dig += "0";a++;}
        dig+=aux;
        aux="";
    }
    aux="";
    int sizeOfDig = dig.size();
    for(int i=0;i<sizeOfDig;i+=2){
        int j=0;
        while(j != 2){
            aux+=dig[i+j];
            j++;
        }
        Dig=stringTozz(aux);
        pos=to_int(Dig);
        msn+=alfabeto[pos];
        aux="";
    }
    return msn;/// msn == P
}

