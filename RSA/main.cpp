#include <iostream>
#include <fstream>
#include <NTL/ZZ.h>
#include "AriMod.h"
#include <stdlib.h>
#include <string>
#include "RSA.h"

using namespace std;
using namespace NTL;

int main(){

///----------------------------------------------
  //
    RSA receptor(512);

    ZZ a=receptor.gete();//to_ZZ();
    ZZ b=receptor.getn();//to_ZZ();
    RSA emisor(a,b);

///----------------------------------------------
    string mensaje = emisor.cifrar("Hay cosas que olvidamos... Y hay cosas que no podemos olvidar, es gracioso, no se cual es mas triste");

    ///ESCRITURA
    ofstream Enumeros("datos.txt");
    ofstream Ecifrado("textoC.txt");
    //string nn="N"+zzToString(receptor.getn())+"\te"+zzToString(receptor.gete())+"\td"+zzToString(receptor.getd())+"\tp"+zzToString(receptor.getp())+"\tq"+zzToString(receptor.getq())+"\t";
    string nn="N"+zzToString(receptor.getn())+"\te"+zzToString(receptor.gete())+"\t";
    Enumeros<<nn<<endl;
    Ecifrado<<mensaje<<endl;
    Enumeros.close();
    Ecifrado.close();

    ///LECTURA
    ifstream Larchivo,Ldatos;
    string leido,data;
    Larchivo.open("textoC.txt");
    getline(Larchivo,leido);
    Larchivo.close();

    Ldatos.open("datos.txt");
    getline(Ldatos,data);
    Ldatos.close();

    cout<<leido<<endl;
    cout<<receptor.descifra_mensaje(leido)<<endl;
    return 0;
}
