#include <iostream>

using namespace std;


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

long int poten(int base,int exp){
    long int resul=1;
    long int aux=base;
    while(exp > 0){
        if(mod(exp,2)==1)
            resul*=aux;
        aux*=aux;
        exp=exp/2;
    }
    return resul;
}
long int potenmod(int base,int exp,int mode){
    long int resul=1;
    long int aux=base;
    while(exp > 0){
        if(mod(exp,2)==1){
            resul*=aux;
            resul=mod(resul,mode);
        }
        aux*=aux;
        aux=mod(aux,mode);
        exp=exp/2;
    }
    return mod(resul,mode);
}

int main()
{
    long int a = poten(9,16);
    long int b = potenmod(444,343,527);
    cout <<a<< endl;
    cout <<mod(b,27)<< endl;
    return 0;
}
