#include <iostream>

using namespace std;
int mod(int a,int b){
    int q,r;
	q = a/b;
	r = a - (q*b);
	if (r<0)
		r=r+b;
	return r;
}
void random(int seed,int a, int b, int n){
    int aux;
    int x = seed;
    aux = (a*x) + b;
    x = mod(aux,n);
    cout<<"| "<<x;
    while(x!= seed){
        aux = (a*x) + b;
        x = mod(aux,n);
        cout<<" | "<<x;
        }
    cout<<" |"<<endl;
}
int euclidesrecursivo(int a, int b){
    if(b == 0)
        return a;
    else
        return euclidesrecursivo(b, mod(a,b));
}
int euclides(int a,int b){
	int r = mod(a,b);
	while(r!=0){
		a=b;
		b=r;
		r=mod(a,b);
	}
	return b;
}
int mcd(int a, int b,char o){
    int u=1,g=a,x=0,y=b,r,s,q,v;
    while (y!=0){
        r = mod(g,y);
        q = g/y;
        s = u-q*x;
        u=x;g=y;
        x=s;y=r;
    }
    if(b==0){
        g=a;u=1,v=0;
    }
    else
        v=(g-a*u)/b;    ///mcd en G ; inversa de a en u;inversa de b en v
    if(o=='x'){
        if(u<0)
            u=u+b;
        return u;
    }
    else if(o=='y')
        return v;
    else
        return g;
}
int abs(int x){
    int y=x;
    if(x<0)
        y=x *(-1);
    return y;
}
int xx(int a,int b){
if(a==0)
	return b;
else if (b==0)
	return a;
else if ((mod(a,2) == 0) and (mod(b,2)==0))
	return 2 * xx(a/2,b/2);
else if ((mod(a,2) == 0) and (mod(b,2)==1))
	return xx(a/2,b);
else if ((mod(a,2) == 1) and (mod(b,2)==0))
	return xx(a,b/2);
else
	return xx(abs(a-b)/2,a);
}
void swap(int *a,int *b){
int aux=*a;
*a=*b;
*b=aux;
}
int gcd(int a, int b){
    if(a<b)
        swap(a,b);

    int g=1,t;
    while(mod(a,2)==0 and mod(b,2)==0){
        a/=2; b/=2; g*=2;
    }
    while(a!=0){
        cout<<a<<b<<endl;
        while(mod(a,2)==0)
            a/=2;
        while(mod(b,2)==0)
            b/=2;
        t=abs(a-b)/2;
        if(a>=b)
            a=t;

    }
    return g *b;
}
int main()
{
    //random(0,3,7,11);
    //cout<<euclidesrecursivo(412,0)<<endl;
    //cout<<euclides(412,260)<<endl;
    ///'x' para la inversa del priemro y 'y' para el del segundo
   // cout<<mcd(7,480,'y')<<endl;
    cout<<xx(23,15)<<endl;
    cout<<gcd(15,2)<<endl;
    return 0;
}
