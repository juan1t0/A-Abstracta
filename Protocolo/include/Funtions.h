#ifndef FUNTIONS_H
#define FUNTIONS_H

#include <NTL/ZZ.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace NTL;
using namespace std;

ZZ raizPrimitiva(ZZ nro);
ZZ modulozz(ZZ a,ZZ b);
int moduloint(int a, int b);
ZZ mcdzz(ZZ a,ZZ b);
int mcdint(int a, int b);
ZZ inversoMultiplicativoZZ(ZZ a,ZZ b);
ZZ valorAbsoluto(ZZ a);
ZZ potenciaModular(ZZ n1,ZZ n2,ZZ mod);
ZZ stringToZZ(string nro);
string zzToString(ZZ nro);
bool Fermat(int num,ZZ primo);

int rdtsc();
void swag(int a1,int a2,vector<bool> *b);
void corrimientoAlaDerecha(vector<bool> *b,int,int,int);
void corrimientoAlaIzquierda(vector<bool> *b,int,int,int);
ZZ toDecimal(vector<bool> *b,int);
ZZ generadorAleatorio(int,int,int,int);

void simpleDesplazamientoIzq(vector<bool> *b);
vector<ZZ> DES(void);

#endif // FUNTIONS_H
