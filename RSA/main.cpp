#include <iostream>
#include <NTL/ZZ.h>
#include "AriMod.h"
#include <stdlib.h>
#include <time.h>
#include "RSA.h"

using namespace std;
using namespace NTL;

int main(){
    srand(time(NULL));
    RSA receptor;
    //RSA emisor(to_ZZ(41),to_ZZ(167),to_ZZ(211));
    //vector<ZZ> texto = emisor.encriptar("Red");
   // string texto2=receptor.desencriptar(texto);
   // cout<<texto2<<endl;
   // RSA r;
   // int a[]={396,0,19049,16911,12282,2645,23037,21558,2645,26338,6513,14993,23037,6513,26338,2645,19767};
   // vector<ZZ> s;
   // for(int i=0;i<17;i++)
     //   s.push_back(to_ZZ(a[i]));
     vector<ZZ> texto;
     int a[]={4696,34987,31361};
     for(int i=0;i<3;i++)
        texto.push_back(to_ZZ(a[i]));
  //  cout<<receptor.desencriptar(texto,to_ZZ(3401),to_ZZ(35237))<<endl;
    cout<<receptor.desencriptar(texto,to_ZZ(3401),to_ZZ(35237))<<endl;
    return 0;
}
/**
publica 41
privada 3401
N 35237
p 167
q 211

C=34860
------------------------------------------------
4696
34987
31361 **/
