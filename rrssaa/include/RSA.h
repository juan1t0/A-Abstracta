#include <iostream>
#include <NTL/ZZ.h>
#include "AriMod.h"
#include "GA.h"
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
        /// CLAVES PARA FIRMAR
        ZZ d_firmar;
        ZZ e_firmar;
        ZZ N_firmar;
      //  string alfabeto="abcdefghijklmnñopqrstuvwxyz ABCDEFGHIJKLMNÑOPQRSTUVWXYZ.,;:";
        string firma="JuanPablo Andrew Herdia Parillo";
    public:
        RSA(int);
        RSA(ZZ,ZZ,int);
        void Generar_claves(int);///ZZ generar_aleatorio(int);
        virtual ~RSA(void);
        ZZ exponenciacion(ZZ,ZZ);
        ZZ resto_chino (ZZ);
        string cifrar(string);
        string descifra_mensaje(string,ZZ,ZZ);
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
