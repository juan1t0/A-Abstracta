#ifndef ELGAMAL_H
#define ELGAMAL_H
#include <iostream>
#include <vector>
#include <string>
#include <NTL/ZZ.h>
#include "AriMod.h"

using namespace std;
using namespace NTL;

class ElGamal
{
    ZZ p;
    ZZ e1;
    ZZ e2;
    ZZ d;
    ZZ r;
    ZZ Km;
    string alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,.;";
    public:
        ElGamal(){}
        ElGamal(int);
        ElGamal(ZZ,ZZ,ZZ);
        virtual ~ElGamal();
        void generarClaves(int);
        ZZ raizPrimitiva();
        string cifrar(string);
        string descifra_mensaje(string);

        ZZ getP();
        ZZ getE1();
        ZZ getE2();
        ZZ getD();
        void setP(ZZ);
        void setE1(ZZ);
        void setE2(ZZ);
        void setD(ZZ);
};

#endif // ELGAMAL_H
