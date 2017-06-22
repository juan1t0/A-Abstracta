#include "AriMod.h"
#include <stdlib.h>
#include <time.h>

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

ZZ inversoMult(ZZ a, ZZ m){
	ZZ s1=to_ZZ(1), t1=to_ZZ(0), s2=to_ZZ(0), t2=to_ZZ(1),q ,r ,s ,t;
	while(m>0){
		q=a/m;
		r=modulo(a,m);
		a=m;
		m=r;
		s=s1-q*s2;
		s1=s2;
		s2=s;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	return s1;
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
ZZ convertir_decimal(vector <bool> a, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(a[i]==1)
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}

