#include "Cesar.h"

Cesar::Cesar(int clav)
{
    clave = clav;
}

Cesar::~Cesar()
{
    //dtor
}
void Cesar::setClave(int cl){
    clave = cl;
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
string Cesar::crip(string word){
    string cod;
    int j=0 ,aux,siz=abc.size(),w=word.size();
    for(int i=0;i<w;i++){
        j= abc.find(word[i]);
        aux=j+clave;
        if (aux > siz)
            aux = mod(aux,siz);
        cod=cod+ abc[aux];
        j=0;
    }
    return cod;
}
string Cesar::descrip(string other){
    string word;
    int j=0,aux,siz=abc.size(),o=other.size();
    for(int i=0;i<o;i++){
        j=abc.find(other[i]);
        aux=j-clave;
        if (aux < 0)
            aux = mod(aux,siz);
        word=word+ abc[aux];
        j=0;
    }
    return word;
}
