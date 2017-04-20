#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Lcg.h"

using namespace std;
int main()
{
    srand(time(NULL));
    int seed=rand()%20;
    Lcg p(seed,10,4,27);
    p.aleatorio(30);
    return 0;
}


