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
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;
        string alfabeto;
    public:
        RSA(int);
        RSA(ZZ,ZZ);
        void Generar_claves(int);
        virtual ~RSA(void);
        ZZ getn();
        ZZ getpp();
        ZZ geta();
        ZZ exponenciacion(ZZ,ZZ);
///ZZ resto_chino (ZZ);
///string cifrar(string);
///string descifra_mensaje(string);
        long euclides(ZZ,ZZ);
        vector<ZZ> extendido_euclides(ZZ,ZZ);
        ZZ inversa(ZZ,ZZ);
///ZZ generar_aleatorio(int);
        bool test_primalidad(ZZ);

    vector<ZZ> encriptar(string mensaje);
    string desencriptar(vector<ZZ> mensaje,ZZ,ZZ);
};
#endif // RSA_H
