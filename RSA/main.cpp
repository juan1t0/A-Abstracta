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
/*
    ///LECTURA
    ifstream Larchivo,Ldatos;
    string leido,data;
    Larchivo.open("textoC.txt");
    getline(Larchivo,leido);
    Larchivo.close();
    Ldatos.open("datos.txt");
    getline(Ldatos,data);
    Ldatos.close();
    ZZ NN=getNWithTap(data);
    ZZ ee=getEWithTap(data);
    cout<<NN<<" "<<ee<<endl;*/
    /*
    ///ESCRITURA
    ofstream Enumeros("datos.txt");
    ofstream Ecifrado("textoC.txt");
    string nn="N131\te46\tjuanpablo.heredia@ucsp.edu.pe";
    string cc="6426455785345256347588542";
    Enumeros<<nn<<endl;
    Ecifrado<<cc<<endl;
    Enumeros.close();
    Ecifrado.close();*/

///----------------------------------------------
    RSA receptor(18);
    RSA emisor(receptor.getpp(),receptor.getn());
//    vector<ZZ>text = emisor.encriptar("Manchester");
  //  cout<<receptor.desencriptar(text,receptor.geta(),receptor.getn())<<endl;
   // cout<<potenciaMod(to_ZZ(15252181),to_ZZ(15727521),to_ZZ(727275843))<<endl;
///----------------------------------------------
    string mensaje = emisor.cifrar("manchester is red");
    cout<<mensaje<<endl;
    cout<<receptor.descifra_mensaje(mensaje)<<endl;
    return 0;
}
