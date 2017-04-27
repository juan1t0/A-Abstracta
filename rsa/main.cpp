#include <iostream>
#include <string>
#include "RSA.h"

using namespace std;

int main()
{
    long int *a;
    RSA receptor;
    long int k = receptor.getPublica();
    int P=receptor.getP();
    int Q=receptor.getQ();
    RSA emisor(k,P,Q);
    a=emisor.criptar("an");
    cout<<*a<<endl;
    cout<<receptor.descriptar(a)<<endl;
    return 0;
}
