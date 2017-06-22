#include <iostream>
#include <fstream>
#include "Funtions.h"
#include "ELRSMAL.h"

using namespace std;

int main(){
///variables
    char opcion;
    ZZ e,N,g,q;
    string cinE, cinN,cing,cinq,cinTxt,opciondEncr;
    string cText;
    ifstream texto;
    string plainText,encriptado,desencrip,opd;
    ofstream cifrado;
    int bits = 64;
///first menu
    cout<<"  ______________________________________  "<<endl;
    cout<<"||--------------------------------------||"<<endl;
    cout<<"||         - - - PROTOCOLO - - -        ||"<<endl;
    cout<<"||______________________________________||"<<endl;
    cout<<"  --------------------------------------  "<<endl;
    cout<<endl<<"Bienvenido al RSA"<<endl<<"Ingrese una opcion:"<<endl;
    cout<<"0 -> Salir"<<endl;
    cout<<"1 -> Encriptar"<<endl;
    cout<<"2 -> Desencriptar"<<endl;
///create RSA
    ELRSMAL receptor(bits);
///main menu
    while(true){
        cout<<"Ingrese una opcion:"<<endl;
        cin>>opcion;
        if(opcion == '0'){
            break;}
        else if(opcion == '1'){
cout<<"--------------Encriptar---------------"<<endl;
            cout<<"e:"<<endl;cin>>cinE;
            e = stringToZZ(cinE);
            cout<<"N:"<<endl;cin>>cinN;
            N = stringToZZ(cinN);
            cout<<"G:"<<endl;cin>>cing;
            g = stringToZZ(cing);
            cout<<"q:"<<endl;cin>>cinq;
            q = stringToZZ(cinq);

            ELRSMAL emisor(N,e,g,q);
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
            desencrip=receptor.desifrar(cText);
            cout<<desencrip<<endl;
            }
        else
            cout<<"upps! ...opcion invalida"<<endl;
    }
///fin
    cout<<"Hasta Luego"<<endl;/*
    ELRSMAL receptor(32);
    ELRSMAL emisor(receptor.N,receptor.e,receptor.G,receptor.primoQ);
    string c=emisor.cifrar("h");
    cout<<c<<endl;
    cout<<"-----------"<<endl;
    cout<<receptor.desifrar(c)<<endl;*/
    return 0;
}
