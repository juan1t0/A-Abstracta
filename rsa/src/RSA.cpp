#include "RSA.h"
///------------------------------------------------------

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
///------------------------------------------------------
RSA::RSA()
{
    p=37;q=29;///generar primos
    N=p*q; C=(p-1)*(q-1);
    e=getKpublica();
    d=getKprivada();
    cout<<"Klave publica: "<<e<<" p: "<<p<<" q: "<<q<<endl;
}
RSA::RSA(long int kpubl,int pp,int qq)
{
    this->p=pp;
    this->q=qq;
    this->e=kpubl;
    N=p*q;C=(p-1)*(q-1);
   /// d=getKprivada();
}
RSA::~RSA(){}
long int RSA::getKpublica(){
    srand(time(NULL));
    bool w=false;
    long int ra;
    while(w!=true){
        ra=mod(rand(),N);
        if(mcd(ra,this->C)==1)
            w=true;
    }
    return ra;
}
long int RSA::getKprivada(){
    long int D;
    D=euclidesX(this->e,C,'x');
    return mod(D,C);
}
long int RSA::getPublica(){return this->e;}
int RSA::getP(){return this->p;}
int RSA::getQ(){return this->q;}

long int* RSA::criptar(string msn)
{
    long int* crip;
    int ss=msn.size(), zz=abc.size();
    int j,k;
    long int a[ss];
    for(int i=0;i<ss;i++){
        k= abc.find(msn[i]);
        j=potenmod(k,this->e,this->N);
        a[i]=j;
    }
    crip=a;
    return a;
}
string RSA::descriptar(long int *crip)
{
    this->d=getKprivada();
    string msn;
    int zz=abc.size();
    int h,k;
    for(;*crip!='\0'; crip++){
        h=potenmod(*crip,this->d,this->N);
        msn+=abc[h];
    }
    return msn;
}
