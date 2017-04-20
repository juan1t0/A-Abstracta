#include "Lcg.h"

Lcg::Lcg(int x,int a, int c, int m)
{
    X0=x;
    this->a=a;this->c=c;this->m=m;
}

Lcg::~Lcg()
{
    //dtor
}
void Lcg::aleatorio(int cant){
    for(int i=0; i<cant; i++){
        X0 = ((a * X0) + c) % m;
        std::cout << X0 <<',';
        }
}
