#include "RSA.h"
void RSA::Generar_claves(){
        ZZ p = ga(5,8,3,3);
        ZZ q = ga(5,8,2,4);
        while(ProbPrime(p,10)!=1)
        {
            p = ga(5,8,3,3);
        }
        while(ProbPrime(q,10)!=1)
        {
            q = ga(5,8,2,4);
        }
        this->p=p;
        this->q=q;
        N = p * q;
        this->N=N;
        ZZ phi_N = (p - 1) * (q - 1);
        this->C=phi_N;
        e = ga(6,8,5,2);
        while(e > phi_N || euclides(e, phi_N) != 1)
        {
            e = ga(6,8,5,2);
        }
        cout <<"Clave publica: " << e << endl;
        d = modulo(inversoMult(e, phi_N),phi_N);
        cout << "Clave privada: " << d << endl;
        cout <<"N: " << N << endl;
        cout <<"p: "<<p<<" q: "<<q<<endl;
}
RSA::RSA(){
    Generar_claves();
    // cout<<e<<endl;
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
}
RSA::RSA(ZZ publica, ZZ p,ZZ q){
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    e=publica;
    N=p*q;
    C=(p-1)*(q-1);
}
ZZ RSA::getkd(){
    return this->d;
}
vector<ZZ> RSA::encriptar(string mensaje){
        vector<ZZ> message;
        ZZ pos;
        for(int i = 0; i <= mensaje.size()-1; i++){
            pos=to_ZZ(alfabeto.find(mensaje[i]));
            pos=potenciaMod(pos,e,N);
            message.push_back(pos);
            cout<<message[i]<<" , ";
        }
        cout<<endl;
        return message;
}
string RSA::desencriptar(vector<ZZ> mensaje,ZZ priv,ZZ n){
        string message;
        ZZ pos;
        for(int i = 0; i < mensaje.size(); i++){
            pos=mensaje[i];
            //pos=potenciaMod(pos,this->d,N);
            pos=potenciaMod(pos,priv,n);
            message+=alfabeto[to_int(pos)];
        }
        return message;
}
