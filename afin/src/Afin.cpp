
///--------------------------------------------------------------------

int mod(int a , int b){
	int q,r;
	q = a/b;
	r = a - (q*b);
	if (r<0){
		r=r+b;
	}
	return r;
}

int mcd(int a,int b){
	int r = mod(a,b);
	while(r!=0){
		a=b;
		b=r;
		r=mod(a,b);
	}
	return b;
}

int inversomod(int a,int b,char o){

    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 -q*x2;
        x1 = x2;
        x2 = x;

        y = y1 - q*y2;
        y1 = y2;
        y2 = y;
    }

    if(o == 'x')
        return x1;
    return y1;

}
int euclidesX(int a,int b,char c){
    if(c=='d')
        return mcd(a,b);
    else if(c=='x' or c=='y')
        return inversomod(a,b,c);
}

///--------------------------------------------------------------------

#include "Afin.h"

int Afin::getA(){
    int s = abc.size(), a;
    bool e = false;

    srand (time(NULL));

    while(e!= true){
        a = rand() % 100 + 1;
        if(mcd(a,s)==1)
            e=true;
    }

    return a;
}

int Afin::getB(){
    int s = abc.size(),b;

    srand (time(NULL));
    b = rand() % s ;

    return b;
}

Afin::Afin()
{
    a=getA();
    b=getB();
}

Afin::~Afin(){}

string Afin::emitir(string origen){
    int s=abc.size(),j,aux, z=origen.size();
    string crip;

    for(int i=0;i<z;i++){
        j=abc.find(origen[i]);
        aux = (j*a)+b;
        crip+=abc[mod(aux,s)];
    }

    return crip;
}

string Afin::recivir(string crip){
    int s=abc.size(),j,aux,aa,z=crip.size();
    string master;

    for(int i=0;i<z;i++){
        j=abc.find(crip[i]);
        aa=(euclidesX(this->a,s,'x'));
        if (aa <0)
            aa=mod(aa,s);
        aux = (j-b)*aa;
        master+=abc[mod(aux,s)];
    }

    return master;
}
