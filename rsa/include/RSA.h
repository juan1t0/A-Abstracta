#ifndef RSA_H
#define RSA_H


class RSA
{
    public:
        string abc("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;");
        RSA();
        RSA(long int publica);
        virtual ~RSA();
    private:
        double p,q;
        long int N,C;
        long int e,d;

        long int getKpublica();
        long int getKprivada();
};

#endif // RSA_H
