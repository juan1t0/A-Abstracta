#include <iostream>
#include <fstream>
#include <NTL/ZZ.h>
#include "AriMod.h"
#include <stdlib.h>
#include <string>
#include "RSA.h"

#define bits 32

using namespace std;
using namespace NTL;

int main(){
///variables
    char opcion;
    ZZ e,N;
    string cinE, cinN,cinTxt,opciondEncr;
    string cText;
    ifstream texto;
    string plainText,encriptado,desencrip,opd;
    ofstream cifrado;
///first menu
    cout<<"  ______________________________________  "<<endl;
    cout<<"||--------------------------------------||"<<endl;
    cout<<"||            - - - RSA - - -           ||"<<endl;
    cout<<"||______________________________________||"<<endl;
    cout<<"  --------------------------------------  "<<endl;
    cout<<endl<<"Bienvenido al RSA"<<endl<<"Ingrese una opcion:"<<endl;
    cout<<"0 -> Salir"<<endl;
    cout<<"1 -> Encriptar"<<endl;
    cout<<"2 -> Desencriptar"<<endl;
///create RSA
    RSA receptor(bits);
///main menu
    while(true){
        cout<<"Ingrese una opcion:"<<endl;
        cin>>opcion;
        if(opcion == '0'){
            break;}
        else if(opcion == '1'){
cout<<"--------------Encriptar---------------"<<endl;
            cout<<"Clave Publica"<<endl;cin>>cinE;
            e = stringTozz(cinE);
            cout<<"Ingrese N"<<endl;cin>>cinN;
            N = stringTozz(cinN);
            RSA emisor(e,N,bits);
            cout<<"Para ingresar .txt pulse 1, para ingresar su propio texto 2"<<endl;
            cin>>opcion;
            if(opcion == '1'){
                cin>>opciondEncr;
                texto.open(opciondEncr);
                getline(texto,plainText);
                texto.close();
            }
            else if(opcion == '2')
                cin>>plainText;
            else{
                cout<<"upps! opcion incorrecta, regresas al menu principal"<<endl;
                continue;
            }
            encriptado = emisor.cifrar(plainText);
            cout<<encriptado<<endl;
            cifrado.open("Cifrado.txt");
            cifrado<<encriptado<<endl;
            cifrado.close();
            }
        else if(opcion == '2'){
cout<<"-------------Desencriptar--------------"<<endl;
            cout<<"Para ingresar su texto cifrado por .txt pulse 1, para hacerlo directo 2"<<endl;
            cin>>opcion;
            if(opcion == '1'){
                cin>>cinTxt;
                texto.open(cinTxt);
                getline(texto,cText);
                texto.close();
            }
            else if(opcion == '2')
                cin>>cText;
            else{
                cout<<"upps! opcion incorrecta, regresas al menu principal"<<endl;
                continue;
            }
            cout<<"ingrese la clave publica y N del emisor:"<<endl;
            cin>>opd;ZZ publica(stringTozz(opd));
            cin>>opd;ZZ nn(stringTozz(opd));
            desencrip=receptor.descifra_mensaje(cText,publica,nn);
            cout<<desencrip<<endl;
            }
        else
            cout<<"upps! ...opcion invalida"<<endl;
    }
///fin
    cout<<"Hasta Luego"<<endl;
      return 0;
}
