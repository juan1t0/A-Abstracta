#include "AriMod.h"

#include <stdlib.h>
//#include <time.h>

using namespace std;
using namespace NTL;
ZZ TRC(vector<ZZ> a,vector<ZZ> p){
    vector<ZZ> q;
    vector<ZZ> Pi;
    ZZ P=to_ZZ(1);
    int sizz = p.size();
    for(int i=0;i<sizz;i++)
        P*=p[i];
    for(int i=0;i<sizz;i++){
        Pi.push_back(P/p[i]);
        q.push_back(inversoMult(Pi[i],p[i]));
    }
    ZZ R;
    for(int i=0;i<sizz;i++)
        R+=modulo(a[i]*q[i]*Pi[i],P);
    R = modulo(R,P);
    return R;
}

ZZ modulo(ZZ a, ZZ b){
	ZZ q,r;
	q=a/b;
	r=a-(q*b);
	if(r<0){
		q--;
		r+=b;
	}
	return r;
}
int moduloInt(int a,int b){
    int q,r;
	q=a/b;
	r=a-(q*b);
	if(r<0){
		q--;
		r+=b;
	}
	return r;
}
string zzToString(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}
ZZ stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}
ZZ euclides(ZZ a, ZZ b){
	ZZ r=modulo(a,b);
	while(r>0){
		a=b;
		b=r;
		r=modulo(a,b);
	}
	return b;
}
ZZ inversoMult(ZZ E, ZZ n){
    ZZ n0 = n, temp, q;
    ZZ E0 = to_ZZ(0);
    ZZ E1 = to_ZZ(1);
    while (E > 1){
        if(n==0){
            cout<<"hey meepo"<<endl;
            ;}
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

ZZ potenciaMod(ZZ n, ZZ m, ZZ mod){
	ZZ resultado=to_ZZ(1);
	while(m>0){
		if(modulo(m,to_ZZ(2))==1)
			resultado=modulo(n*resultado,mod);
		m=m/2;
		n=modulo(n*n,mod);
	}
	return resultado;
}
ZZ valorAb(ZZ A){
    if(A >= 0)
        return A;
    else
        return A*(-1);
}
ZZ phi_euler(ZZ p){
    if( p== 0 || p==1)
        return p;
    else if(ProbPrime(p,10)==1)
        return p-1;
    /*else{
        vector<ZZ> f = factorizarDivicion(p);
        int i=0,siz=f.size();
        ZZ phi=to_ZZ(1);bool pot=false;
        while(i<siz){
            if(i+1 == siz){
                phi*= phi_euler(f[i]);break;}
            if(f[i]!=f[i+1])
                phi*= phi_euler(f[i]);
            pot=true;i++;
        }
        if(pot == false)
            return phi;
        phi=to_ZZ(1);i=0;
        for(int c=1;i<siz;c++,i++){
            if(i+1 == siz){
                phi*= f[i]-1;break;}
            if(f[i]!=f[i+1])
                phi*= f[i]-1;
            pot=true;
        }

    }*/
}
vector<ZZ> factorizarDivicion(ZZ n){
    vector<ZZ>a;
    ZZ A=to_ZZ(2);
    ZZ rc= SqrRoot(n);
    while(A <= rc){
        while(modulo(n,A)==0){
            a.push_back(A);
            n=n/A;
        }
        A = A+1;
    }
    if(n>1)
        a.push_back(n);
    return a;
}
vector<ZZ> criba_cuadratica(ZZ n){}

ZZ Primitiva(ZZ p){
    ZZ q=(p-1)/2,g;

    for(int i=1;i<p-1;i++){
        g = p-i;
        cout<<"a";
        if((potenciaMod(g,to_ZZ(2),p)!=1) && (potenciaMod(g,q,p)!= 1))
            return g;
    }
    return g;
}
string numberToString(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}

