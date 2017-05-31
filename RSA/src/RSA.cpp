#include "RSA.h"
#include <math.h>

RSA::RSA(int bits){
    Generar_claves(bits);
}
RSA::RSA(ZZ publica, ZZ n){
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
    long mcd = 1;
    ZZ t;
    while(modulo(a,to_ZZ(2))== 0 && modulo(b,to_ZZ(2))== 0){
        a = a/2;
        b = b/2;
        mcd = mcd*2;
    }
    while(a != 0){
        while(modulo(a,to_ZZ(2))== 0){a = a/2;}
        while(modulo(b,to_ZZ(2))== 0){b = b/2;}
        t = valorAb(a-b)/2;
        if(a >= b)
            a = t;
        else
            b = t;
    }
    return(mcd * to_int(b));
}
void RSA::Generar_claves(int bs){
        int ss=11;
        int pp=sqrt(bs);
        p = ga(ss,bs,pp,13);
        q = ga(ss+5,bs,pp,14);
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
    ZZ a = modulo(ga(10,16,4,8),x-2)+1;
    if(potenciaMod(a,x-1,x)== 1)
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
ZZ RSA::resto_chino(ZZ c){
    ZZ D;
    ZZ d1 = modulo(this->d,this->p -1);
    ZZ d2 = modulo(this->d,this->q -1);
    ZZ a1 = exponenciacion(c,d1);
    ZZ a2 = exponenciacion(c,d2);
    ZZ q1 = inversa(q,p);
    ZZ q2 = inversa(p,q);
    D = modulo(a1 * q * q1,this->N);
    D+= modulo(a2 * p * q2,this->N);
    return modulo(D,this->N);
}

string RSA::cifrar(string mensaje){
    string msn;
    string dig;
    ZZ Dig;
    int pos, sizeOfMensaje = mensaje.size();
    ///PROCESAMIENTO DEL TEXTO
    for(int i=0;i<sizeOfMensaje;i++){
        pos = alfabeto.find(mensaje[i]);
        if(pos<10)
            dig+="0";
        dig+=zzToString(to_ZZ(pos));
    }
    ZZ temp = to_ZZ(dig.size());
    ZZ nless1= to_ZZ(zzToString(this->N).size() -1);
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
        Dig = exponenciacion(Dig,this->e);
        aux = zzToString(Dig);
        int a = aux.size();
        while(to_ZZ(a) < nless1+1){
            a++; axe += "0";
        }
        axe+=aux;
        msn+=axe;
        aux="";axe="";
    }
    return msn;
}
string RSA::descifra_mensaje(string cifrado){
    string msn;
    string dig;

    ZZ Dig;
    ZZ nlen = to_ZZ(zzToString(this->N).size());

    int pos=0 , sizeOfCifrado = cifrado.size(), nlo=to_int(nlen);
    string aux;
    for(int i=0;i<sizeOfCifrado;i+=nlo){
        int j=0;
        while(j < nlo){
            aux+=cifrado[j+i];
            j++;
        }
        Dig = stringTozz(aux);
        Dig = resto_chino(Dig);
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
    return msn;
}
ZZ RSA::getn(){return N;}
ZZ RSA::gete(){return e;}
ZZ RSA::getd(){return d;}
ZZ RSA::getp(){return p;}
ZZ RSA::getq(){return q;}

void RSA::setNWithTap(string tp){
    int p=tp.find('N');
    string num;
    p++;
    while(tp[p]!='\t'){
        num+=tp[p];
        p++;
    }
    this->N= stringTozz(num);
}
void RSA::setEWithTap(string tp){
    int p=tp.find('e');
    string num;
    p++;
    while(tp[p]!='\t'){
        num+=tp[p];
        p++;
    }
    this->e= stringTozz(num);
}
void RSA::setDWithTap(string tp){
    int p=tp.find('d');
    string num;
    p++;
    while(tp[p]!='\t'){
        num+=tp[p];
        p++;
    }
    this->d= stringTozz(num);
}
void RSA::setPWithTap(string tp){
    int p=tp.find('p');
    string num;
    p++;
    while(tp[p]!='\t'){
        num+=tp[p];
        p++;
    }
    this->p= stringTozz(num);
}
void RSA::setQWithTap(string tp){
    int p=tp.find('q');
    string num;
    p++;
    while(tp[p]!='\t'){
        num+=tp[p];
        p++;
    }
    this->q= stringTozz(num);
}


/**
string RSA::cifrar(string mensaje){
        string message;
        string temp="";
        string letra;
        string aux;
        ZZ num;
        int tam = zzToString(to_ZZ(alfabeto.length()-1)).length();
        int tamN= zzToString(N).length();
        for(int i=0;i<mensaje.length();i++){
                letra=zzToString(to_ZZ(alfabeto.find(mensaje[i])));
                while(letra.length()<tam){
                    aux=letra;
                    letra="0";
                    letra+=aux;
                }
                temp+=letra;
        }
        while(temp.length()%(tamN-1)!=0){
                temp+=zzToString(to_ZZ(alfabeto.find("#")));
        }
        for(int i=0;i<temp.length();i+=tamN-1){
            letra="";
            for(int j=0;j<tamN-1;j++){
                letra+=temp[j+i];
            }
            num=potenciaMod(stringTozz(letra),e,N);
            letra=zzToString(num);
            while(letra.length()<tamN){
                aux=letra;
                letra="0";
                letra+=aux;
            }
            message+=letra;
        }
        return message;
}*/
/**
string RSA::descifra_mensaje(string mensaje){
        string message;
        string letra;
        string temp;
        string aux;
        ZZ num;
        int tam = zzToString(to_ZZ(alfabeto.length()-1)).length();
        int tamN= zzToString(N).length();
        for(int i=0;i<mensaje.length();i+=tamN){
            letra="";
            for(int j=0;j<tamN;j++){
                letra+=mensaje[j+i];
            }
            num=stringTozz(letra);
            letra=zzToString(resto_chino(num));
            while(letra.length()<tamN-1){
                aux=letra;
                letra="0";
                letra+=aux;
            }
            temp+=letra;
        }
        for(int i=0;i<temp.length();i+=tam){
            letra="";
            for(int j=0;j<tam;j++){
                letra+=temp[j+i];
            }
            message+=alfabeto[to_int(stringTozz(letra))];
        }
        while(message[message.length()-1]=='#'){
            aux="";
            for(int i=0;i<message.length()-1;i++)
                aux+=message[i];
            message=aux;
        }
        return message;
}*/

