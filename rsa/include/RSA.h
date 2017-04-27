#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
//string abc = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;"};
class RSA
{
    public:
        string abc = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;"};

        RSA();
        RSA(long int,int,int);
        virtual ~RSA();

        long int getPublica();
        int getP();
        int getQ();
        long int* criptar(string);
        string descriptar(long int*);
    private:
        int p,q;
        long int N,C;
        long int e,d;

        long int getKpublica();
        long int getKprivada();
};
#endif // RSA_H
