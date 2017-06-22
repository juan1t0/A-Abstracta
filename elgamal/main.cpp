#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>

#include "ElGamal.h"
#include "AriMod.h"
#include "GA.h"
using namespace std;
using namespace NTL;

int main(){
///variables
    char opcion;
    ZZ e1,e2,P;
    string cinE, cinN,cinTxt,opciondEncr;
    string cText;
    ifstream texto;
    string plainText,encriptado,desencrip;
    ofstream cifrado;
///first menu
    cout<<"  ______________________________________  "<<endl;
    cout<<"||--------------------------------------||"<<endl;
    cout<<"||          - - - ElGamal - - -         ||"<<endl;
    cout<<"||______________________________________||"<<endl;
    cout<<"  --------------------------------------  "<<endl;
    cout<<endl<<"Bienvenido a El Gamal"<<endl<<"Ingrese una opcion:"<<endl;
    cout<<"0 -> Salir"<<endl;
    cout<<"1 -> Encriptar"<<endl;
    cout<<"2 -> Desencriptar"<<endl;
///create ElGamal
    ElGamal receptor(16);
///main menu
    while(true){
        cout<<"Ingrese una opcion:"<<endl;
        cin>>opcion;
        if(opcion == '0'){
            break;}
        else if(opcion == '1'){
cout<<"--------------Encriptar---------------"<<endl;
            cout<<"Clave Publica 1 (e1)"<<endl;cin>>cinE;
            e1 = stringTozz(cinE);
            cout<<"Clave Publica 2 (e2)"<<endl;cin>>cinE;
            e2 = stringTozz(cinE);
            cout<<"Ingrese p"<<endl;cin>>cinN;
            P = stringTozz(cinN);
            ElGamal emisor(e1,e2,P);
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
            desencrip=receptor.descifra_mensaje(cText);
            cout<<desencrip<<endl;
            }
        else
            cout<<"upps! ...opcion invalida"<<endl;
    }
///fin
    cout<<"Hasta Luego"<<endl;

    return 0;
}
