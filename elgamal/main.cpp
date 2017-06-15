#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>

#include "ElGamal.h"
#include "AriMod.h"
#include "GA.h"

using namespace std;
using namespace NTL;

int main()
{
    ElGamal r;
    ElGamal receptor(64);
    ZZ a = receptor.getE1(),b=receptor.getE2(),c=receptor.getP();
    ElGamal emisor(a,b,c);
    cout<<"<------------------------------------>"<<endl;
    string l = emisor.cifrar("Oculto por la noche, pero con paso firme. Tenhido por la sangre, pero con la mente despejada.");
    ///string l = emisor.cifrar("Escuchad mis palabras, sed testigos de mi juramento...   La noche se avecina, ahora empieza mi guardia. No terminara hasta el dia de mi muerte. No tomare esposa, no poseere tierras, no engendrare hijos. No llevare corona, no alcanzare la gloria. Vivire y morire en mi puesto.  ...Soy la espada en la oscuridad. Soy el vigilante del muro. Soy el fuego que arde contra el frio, la luz que trae el amanecer, el cuerno que despierta a los durmientes, el escudo que defiende los reinos de los hombres. Entrego mi vida y mi honor a la Guardia de la Nocha, durante esta noche y todas las que esten por venir. JuanPablo Andrew Heredia Parillo juanpablo.heredia ucsp.edu.pe");
    cout<<"<------------------------------------>"<<endl;
    ///ESCRITURA
    ofstream Enumeros("datos.txt"), Emisk("claves.txt");
    ofstream Ecifrado("textoC.txt");
    string mm="p: "+zzToString(receptor.getP())+"\te1: "+zzToString(receptor.getE1())+"\te2: "+zzToString(receptor.getE2())+"\td: "+zzToString(receptor.getD())+"\t";
    string nn="p: "+zzToString(receptor.getP())+"\te1: "+zzToString(receptor.getE1())+"\te2: "+zzToString(receptor.getE2())+"\t";
    Enumeros<<nn<<endl;
    Ecifrado<<l<<endl;
    Emisk<<mm<<endl;
    Enumeros.close();
    Ecifrado.close();
    Emisk.close();
    cout<<"<------------------------------------>"<<endl;
    ///LECTURA
    ifstream Larchivo("textoC.txt");
    string leido;
    getline(Larchivo,leido);
    Larchivo.close();
    cout<<leido<<endl;
    cout<<"<------------------------------------>"<<endl;
    ///...........................
 /*   r.setD(stringTozz("98919550896239194854906140153435563189"));//receptor.getD());//
    r.setP(stringTozz( "218964166342698383526704352558440058859"));//receptor.getP());//
    r.setE1(stringTozz("218964166342698383526704352558440058855"));//receptor.getE1());//
    r.setE2(stringTozz("96468936020080527800261360124222437938"));//receptor.getE2());//
    ///...........................*/
   // cout<<r.descifra_mensaje(leido);/**
    cout<<receptor.descifra_mensaje(leido);
    return 0;
}
