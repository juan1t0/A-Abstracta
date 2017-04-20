#include <iostream>
#ifndef LCG_H
#define LCG_H


class Lcg
{
    public:
        Lcg(int,int,int,int);
        virtual ~Lcg();

        void aleatorio(int);
    private:
        int X0;
        int a,c,m;
};

#endif // LCG_H
