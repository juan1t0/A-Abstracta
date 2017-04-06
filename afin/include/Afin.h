#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
using namespace std;

#ifndef AFIN_H
#define AFIN_H


class Afin
{
    public:
        string abc={"abcdefghijklmnopqrstuvwxyz ,"};

        Afin();
        virtual ~Afin();

        string emitir(string);
        string recivir(string);

    private:
        int a;
        int b;

        int getA();
        int getB();
};

#endif // AFIN_H
