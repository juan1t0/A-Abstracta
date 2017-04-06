#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#ifndef TRANS_H
#define TRANS_H


class Trans
{
    public:
        Trans(int clave);
        virtual ~Trans();

        string transponer(string);
        string poner(string);

    private:
        int clave;
        void llenar(string*);
};

#endif // TRANS_H
