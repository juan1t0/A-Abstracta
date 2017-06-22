#ifndef ARIMOD_H
#define ARIMOD_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a,ZZ b);
ZZ euclides(ZZ a,ZZ b);
ZZ inversoMult(ZZ a,ZZ m);
ZZ valorAb(ZZ);
ZZ potenciaMod(ZZ n,ZZ m,ZZ mod);
string zzToString(ZZ);
ZZ stringTozz(string);
ZZ TRC(vector<ZZ>,vector<ZZ>);
#endif // ARIMOD_H
