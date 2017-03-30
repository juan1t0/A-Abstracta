#include <iostream>
#include <stdio.h>
#include <string>
#include "Trans.h"

using namespace std;

void sin_space(string *frase){
    string space(" ");
    size_t j=frase->find(space);
    while(j!= string::npos){
        frase->erase(j,1);
        j=frase->find(space);
        }

}

int main()
{

    string h("hola como estas");
    string *g = &h;
    sin_space(g);
    cout<<h<<endl;
    Trans un(4);
    string f = un.transponer(h);
    cout<<f<<endl;
 //   cout<<un.poner(f)<<endl;
    return 0;
}
