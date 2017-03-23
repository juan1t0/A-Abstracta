#include <iostream>
#include <stdio.h>
#include <string>
#include "Cesar.h"

using namespace std;

int mode(int a , int b){
	int q,r;
	q=a/b;
	r = a - (q*b);
	if (r<0){
		q= q-1;
		r=r+b;
	}
	return r;
}

int mcd(int a,int b){
	int r = mode(a,b);
	while(r!=0){
		a=b;
		b=r;
		r=mode(a,b);
	}
	return b;
}

int main()
{
    string s;
    Cesar uno;
	//cout<<mod(-255,11)<<endl;
	//cout<<mcd(26,30)<<endl;
    s=uno.crip("paz",3);
    cout<<s<<endl;
	return 0;
}
