#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Cesar
{
    public:
        string abc={"abcdefghijklmnopqrstuvwxyz"};

        Cesar();
        virtual ~Cesar();

        string crip(string word, int clave);
        string descrip(string other, int clave);
};

#endif // CESAR_H
