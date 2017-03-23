#include "Cesar.h"

Cesar::Cesar()
{
 //nothing
}

Cesar::~Cesar()
{
    //dtor
}

int mod(int a , int b){
	int q,r;
	q=a/b;
	r = a - (q*b);
	if (r<0){
		q= q-1;
		r=r+b;
	}
	return r;
}
string Cesar::crip(string word,int clave){
    string cod;
    int j=0 ,aux;
    for(int i=0;i<3;i++){
        while (abc[j]!= word[i])
            j++;
        aux=j+clave;
        if (aux > 26)
            aux = mod(aux,26);
        cod=cod+ abc[aux];
        j=0;
    }
    return cod;
}
string Cesar::descrip(string other, int clave){
    string word;
    int j=0,aux;
    for(int i=0;i<3;i++){
        while (abc[j]!= other[i])
            j++;
        aux=j-clave;
        if (aux < 1)
            aux = mod(aux,26);
        word=word+ abc[aux];
        j=0;
    }
    return word;
}
