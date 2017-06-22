#ifndef ELRSMAL_H
#define ELRSMAL_H

#include <NTL/ZZ.h>
#include "Funtions.h"
using namespace NTL;
using namespace std;


class ELRSMAL
{
public:
    ZZ Fq;
    ZZ primoQ;
    ZZ G;
    ZZ primoGrandeP1 , primoGrandeP2;
    ZZ N;
    ZZ e;
    ZZ d;
    ZZ Ca;
    string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,.;";
public:
    ELRSMAL(int bits);
    ELRSMAL(ZZ ene,ZZ EE,ZZ ge,ZZ qu);
    virtual ~ELRSMAL();

    void generarClaves(int bits);
    string cifrar(string);
    string desifrar(string);
    string Bloques(string);
};

#endif // ELRSMAL_H
