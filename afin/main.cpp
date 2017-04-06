#include <iostream>
#include <stdio.h>
#include "Afin.h"

using namespace std;

int main()
{
    Afin code;
    string h=code.emitir("to infinit and beyond");
    cout<<h<<endl;
    string g=code.recivir(h);
    cout<<g<<endl;
}
