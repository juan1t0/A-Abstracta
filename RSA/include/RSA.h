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
        string alfabeto="abcdefghijklmnñopqrstuvwxyz ABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789.,;:-_()@{}+/";

    public:
        RSA(int);
        RSA(ZZ,ZZ);
        void Generar_claves(int);///ZZ generar_aleatorio(int);
        virtual ~RSA(void);
        ZZ exponenciacion(ZZ,ZZ);
        ZZ resto_chino (ZZ);
        string cifrar(string);
        string descifra_mensaje(string);
        long euclides(ZZ,ZZ);
        vector<ZZ> extendido_euclides(ZZ,ZZ);
        ZZ inversa(ZZ,ZZ);
        bool test_primalidad(ZZ);

        void setNWithTap(string);
        void setEWithTap(string);
        void setDWithTap(string);
        void setPWithTap(string);
        void setQWithTap(string);
        ZZ getn();
        ZZ gete();
        ZZ getd();
        ZZ getp();
        ZZ getq();

};
#endif // RSA_H
