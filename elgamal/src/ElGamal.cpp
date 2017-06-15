#include "ElGamal.h"

ElGamal::ElGamal(int bits){
    generarClaves(bits);
}
ElGamal::ElGamal(ZZ e_1,ZZ e_2,ZZ pp){
    this->e1 = e_1;
    this->e2 = e_2;
    this->p = pp;
    /*int b ;
    cout<<"Ingrese el numero de bits para R : "<<endl;
    cin>>b;
    this->r = ga(11,b,5,23);
    while(r<1 && r>p-2){
        this->r = ga(11,b,5,23);
    }*/
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
    p = ga(17,bits,5,23);
    while(ProbPrime(p,10)!=1 && ProbPrime((p-1)/2,10)!=1)
        p = ga(17,bits,5,23);
    this->e1 = raizPrimitiva();
    this->d = ga(11,bits,5,21);
    this->r = ga(11,bits,5,23);
    while(d <1 && d>p-2){ //)&&(r<1 && r>p-2)){
        this->d = ga(11,bits,5,21);
        this->r = ga(11,bits,5,23);
    }
    this->e2 = potenciaMod(e1,d,p);
    cout<<"p: "<<p<<endl;
    cout<<"e1: "<<e1<<endl;
    cout<<"e2: "<<e2<<endl;
}
string ElGamal::cifrar(string mensaje){
    string res,lString,mensajeC,c1_string;
    int c1_temp;
    ZZ c1;
    c1= potenciaMod(e1,r,p);
    Km = potenciaMod(e2,r,p);
    c1_string =zzToString(c1);
    c1_temp = c1_string.length();
    int lenMaxString = numberToString(alfabeto.size()).length();
    int lenN = zzToString(p).length();
    int k = lenN-1;

    int numOfZeros;
    int l;
    ZZ numGroups;
    int tam_mensaje = mensaje.length();
    for(int i = 0;i<tam_mensaje;i++){
        l = alfabeto.find(mensaje[i]);
        lString = numberToString(l);
        numOfZeros = lenMaxString-lString.length();
        string temp(numOfZeros,'0');
        temp.append(lString);
        res.append(temp);
    }
    string posW = numberToString(alfabeto.find('w'));
    while(moduloInt(res.length(),k)!=0){
        res.append(posW);
    }
    numGroups = to_ZZ(res.length()/k);
    long long i;
    int ini = 0;
    int fin = k;
    for(i=0;i<numGroups;i++){
        ZZ numCifrar(INIT_VAL,res.substr(ini,fin).c_str());
        //numCifrar = m.modularExpo(numCifrar,clavePublica,N);
        numCifrar = modulo(numCifrar*Km,p);
        string t = zzToString(numCifrar);
        int diff = (lenN)-t.length();
        string actualString = t;
        if(diff!=0){
            string temp(diff,'0');
            temp.append(t);
            actualString = temp;
        }
        mensajeC+=actualString;
        ini+=k;
    }
    if(c1_temp<lenN){
        int tempo = lenN-c1_temp;
        string temp(tempo,'0');
        temp+=c1_string;
        temp+=mensajeC;
        mensajeC=temp;
    }else{
        c1_string+=mensajeC;
        mensajeC = c1_temp;
    }
    cout<<"Mensaje Cifrado: "<<mensajeC<<endl;
    return mensajeC;
}
string ElGamal::descifra_mensaje(string mensaje){
    int lenP = zzToString(p).length();
    ZZ c1(INIT_VAL,mensaje.substr(0,lenP).c_str());
    Km=potenciaMod(c1,d,p);
    ZZ Km_1=inversoMult(Km,p);
    string grupo,res,MensajeDes;
    int numMaxofChars = numberToString(alfabeto.size()).length();
    ZZ nLen,menLen,numGrupos,dp,dq,D,c,numLetras;
    nLen = to_ZZ(zzToString(p).length());
    menLen = to_ZZ(mensaje.length());
    numGrupos = menLen/nLen;
    long long i;
    int inicio = lenP;
    c=0;
    for(i=1;i<numGrupos;i++){
        grupo = mensaje.substr(inicio,to_int(nLen));
        ZZ valGrupo(INIT_VAL,grupo.c_str());
        D=modulo(valGrupo*Km,p);
        if(zzToString(D).length() < to_int(nLen)){
            string temp((to_int(nLen)-zzToString(D).length())-1,'0');
            temp.append(zzToString(D));
            res+=temp;
        }else{
           res+=zzToString(D);
        }

        c++;
        inicio+=to_int(nLen);
    }
    inicio = 0;
    numLetras = to_ZZ(res.length())/to_ZZ(numberToString(alfabeto.size()).length());
    for(i=0;i<numLetras;i++){
        ZZ temp(INIT_VAL,res.substr(inicio,numMaxofChars).c_str());
        if(alfabeto[to_int(temp)]=='w'){
            break;
        }
        MensajeDes+=alfabeto[to_int(temp)];
        inicio+=numMaxofChars;
    }
    return MensajeDes;
}
/*
string ElGamal::cifrar(string mensaje){
    string msn;
    string dig;
    ZZ Dig,C1;
    C1=potenciaMod(e1,r,p);
    string C_uno=zzToString(C1);
    Km=potenciaMod(e2,r,p);

    int pos, sizeOfMensaje = mensaje.size();
    int Ctemp = C_uno.size();
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
    cout<<dig<<endl;
    ///----------------------------------
    string aux;
    string axe;
    int sizeOFDig=dig.size(),nm1=to_int(nless1);
    C1 = potenciaMod(e1,r,p);
    Km = potenciaMod(e2,r,p);
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
    return msn;///msn == C2;
}
string ElGamal::descifra_mensaje(string cifrado){
    string msn;
    string dig;
    ZZ Dig,C1;
    ZZ nlen = to_ZZ(zzToString(this->p).size());
    int pos=0 , sizeOfCifrado = cifrado.size(), nlo=to_int(nlen);
    string aux;

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
*/
