#include <iostream>
#include <NTL/ZZ.h>
#include "AriMod.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace NTL;
#ifndef RSA_H
#define RSA_H


class RSA
{
    private:
        ZZ d;
      //  ZZ getkd();
    public:
        string alfabeto;
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;
        ZZ C;
        ZZ getkd();
    void Generar_claves();
    RSA();
    RSA(ZZ ,ZZ ,ZZ );

    vector<ZZ> encriptar(string mensaje);
    string desencriptar(vector<ZZ> mensaje,ZZ,ZZ);
};

#endif // RSA_H
