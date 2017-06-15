#ifndef ARIMOD_H
#define ARIMOD_H
#include <sstream>
#include <string>
#include <NTL/ZZ.h>
#include <vector>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a,ZZ b);
int moduloInt(int ,int);
ZZ euclides(ZZ a,ZZ b);
ZZ inversoMult(ZZ a,ZZ m);
ZZ valorAb(ZZ);
ZZ potenciaMod(ZZ n,ZZ m,ZZ mod);
ZZ convertir_decimal(vector <bool> a, int bits_num);
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas);
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas);
ZZ ga(int bits_seed, int bits_num, int particiones, int vueltas);
string zzToString(ZZ);
ZZ stringTozz(string);
string numberToString(int);
ZZ TRC(vector<ZZ>,vector<ZZ>);
ZZ phi_euler(ZZ);
ZZ jacobi(ZZ,ZZ);
vector<ZZ> criba_cuadratica(ZZ);
vector<ZZ> factorizarDivicion(ZZ);
ZZ Primitiva(ZZ);
#endif // ARIMOD_H
