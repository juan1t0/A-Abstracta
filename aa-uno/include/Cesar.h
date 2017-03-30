#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Cesar
{
    int clave;
    public:
        string abc={"abcdefghijklmnopqrstuvwxyz "};

        Cesar(int clav);
        virtual ~Cesar();

        void setClave(int cl);

        string crip(string word);
        string descrip(string other);
};

#endif // CESAR_H
