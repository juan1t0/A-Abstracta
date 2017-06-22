#include "ELRSMAL.h"

ELRSMAL::ELRSMAL(int bits){
    Fq=generadorAleatorio(37,bits,8,17);
    primoQ = generadorAleatorio(29,bits,8,17);
    while(primoQ<2 && primoQ>Fq && ProbPrime(primoQ,10)!=1)
        primoQ = generadorAleatorio(29,bits,8,17);
    G=raizPrimitiva(Fq);
    ///-----receptor-------
    primoGrandeP1=generadorAleatorio(17,bits,12,19);
    primoGrandeP2=generadorAleatorio(17,bits,12,19);
    while(ProbPrime(primoGrandeP1,10)!=1 && ProbPrime(primoGrandeP2,10)!=1){
        primoGrandeP1=generadorAleatorio(17,bits,12,19);
        primoGrandeP2=generadorAleatorio(17,bits,12,19);
    }
    N=primoGrandeP1 * primoGrandeP2;
    generarClaves(bits);
    cout<<"N: "<<endl<<N<<endl;
    cout<<"e: "<<endl<<e<<endl;
    cout<<"g: "<<endl<<primoQ<<endl;
    cout<<"q: "<<endl<<G<<endl;
}
ELRSMAL::ELRSMAL(ZZ ene,ZZ EE,ZZ ge,ZZ qu){
    N=ene;
    G=ge;
    primoQ = qu;
    e=EE;
    cout<<"emisor"<<endl;
}
ELRSMAL::~ELRSMAL(){}

void ELRSMAL::generarClaves(int bits){
    ZZ phi_N=(primoGrandeP1 -1)*(primoGrandeP2-1);
    e=generadorAleatorio(23,bits,8,13);
    while(e<2 && e>phi_N && mcdzz(e,phi_N)!=1)
        e=generadorAleatorio(23,bits,8,13);
    d=inversoMultiplicativoZZ(e,phi_N);
}
string ELRSMAL::cifrar(string mensaje){
    string cifrado, bloques = Bloques(mensaje),aux;
    int tamBlok=bloques.size(), nlen=zzToString(N).size(),otoaux;
    ZZ xua;
    ZZ a = generadorAleatorio(19,nlen,2,13);
    while(a<2 && a>primoQ)
        a = generadorAleatorio(19,nlen,2,13);
    ZZ k= potenciaModular(G,a,primoQ);
    Ca = potenciaModular(a,e,N);
    for(int i=0;i<tamBlok;i+=(nlen-1)){
        aux=bloques.substr(i,(nlen-1));
        xua=stringToZZ(aux);
        xua = modulozz(xua*k , primoQ);
        aux=zzToString(xua);
        otoaux=aux.size();
        while(otoaux<nlen){
            cifrado+='0';otoaux++;
        }
        cifrado+=aux;
    }
    cifrado+=zzToString(Ca);
    cout<<Ca<<endl;
    return cifrado;

}
string ELRSMAL::desifrar(string cifrado){
    string mensaje, C_a,aux,cuasiMensaje;
    int nlen=zzToString(N).size(),ciLen=cifrado.size();
    int tamAlf = zzToString(to_ZZ(alfabeto.size())).size();
    ZZ xua;

    C_a=cifrado.substr(ciLen-nlen , ciLen);
    Ca=stringToZZ(C_a);
    cifrado = cifrado.substr(0,(ciLen-nlen)-1);
    ZZ a=potenciaModular(Ca,d,N);
    ZZ k=potenciaModular(G,a,primoQ);
    k=inversoMultiplicativoZZ(G,primoQ);
    for(int i=0;i<ciLen;i+=nlen){
        aux=cifrado.substr(i,nlen);
        xua = stringToZZ(aux);
        xua = modulozz(xua*k , primoQ);
        aux = zzToString(xua);
        cuasiMensaje+=aux;
    }
    int tamCM=cuasiMensaje.size();
    for(int i=0;i<tamCM;i+=tamAlf){
        aux=cuasiMensaje.substr(i,tamAlf);
        xua=stringToZZ(aux);
        mensaje+=alfabeto[to_int(xua)];
    }
    return mensaje;


}
string ELRSMAL::Bloques(string mensaje){
    string bloquecitos,aux;
    int tamAlf = zzToString(to_ZZ(alfabeto.size())).size();
    int tamMensaje=mensaje.size();
    ZZ pos;
    for(int i=0;i<tamMensaje;i++){
        pos = to_ZZ(alfabeto.find(mensaje[i]));
        aux = zzToString(pos);
        int a=aux.size();
        while( a< tamAlf){
            bloquecitos+='0';
            a++;
            }
        bloquecitos+=aux;
    }
    int lenOfN =zzToString(N).size();
    int tamBloque=bloquecitos.size();
    while(moduloint(tamBloque,lenOfN-1)!= 0){
        pos = to_ZZ(alfabeto.find('w'));
        bloquecitos+=zzToString(pos);
        tamBloque=bloquecitos.size();
    }
    return bloquecitos;
}
