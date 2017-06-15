#ifndef GA_H
#define GA_H
#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <time.h>

using namespace NTL;
using namespace std;

void swap(int , int , vector<bool> );
void corrimiento_derecha(vector <bool>, int , int, int );
void corrimiento_izquierda(vector <bool> , int , int , int );
ZZ decimal(vector <bool> , int );
int rdtsc();
ZZ ga(int , int , int , int );

#endif // GA_H
