#include "GA.h"
#include "AriMod.h"

void swap(int i, int j, vector<bool>a)
{
    int temp= a[i];
    a[i] = a[j];
    a[j] =temp;
}
void corrimiento_derecha(vector <bool> vec, int indice, int elementos, int vueltas)
{
    srand(time(NULL));
    int pos_aleatoria = rand()% elementos;
    bool bit_ultimo= vec[(elementos*2)-1];
    for(int j =vueltas; j > 0; j--)
    {
        for(int i=(elementos*2)-1-indice ; i>= elementos; i--)
        {
            swap(i, i+1, vec);
        }
    }
    bool x = vec[pos_aleatoria+elementos]^bit_ultimo;
    vec[elementos]= x;
}

void corrimiento_izquierda(vector <bool> vec, int indice, int elementos, int vueltas)
{
    srand(time(NULL));
    int pos_aleatoria = rand()% (elementos-1);
    bool primero = vec[0];
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = 0; i<elementos-1-indice; i++)
        {
            swap(i, i+1, vec);
        }
    }
    bool x= primero^vec[pos_aleatoria];
    vec[elementos-1]=x;
}

ZZ decimal(vector <bool> *b, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(b->at(i)==1)
            (num += power2_ZZ(e));
        else
            (num += to_ZZ(0));
        e += 1;
    }
    return num;
}
int rdtsc() //rand de ciclos utilizados por procesador desde el inicio
{
    __asm__ __volatile__("rdtsc");
}
ZZ ga(int t_seed, int t_bits, int particiones, int vueltas)
{
    vector <bool>binario;
    bool aleatorio_bit_seed= 0;
    for(int i = 0; i < t_bits; i++)
    {
        binario.push_back(0);
    }
    int s=0;   //j pos vector ,s recorre
    for(int i = 0 ; i<t_seed; i++)
    {
        aleatorio_bit_seed= moduloInt(rdtsc(),2);
        binario[i]= aleatorio_bit_seed;
    }
    if(binario[0]==0)
            binario[0]=1;
    for(int i = t_seed; i < t_bits; i++)
    {
        binario[i] = binario[s] ^ binario[s+1]; //concatenar xor
        s++;
    }
    int partes=t_bits/particiones; //cuantos bits tiene cada parte
    int residuo_partes= moduloInt(t_bits,particiones); //por si no es exacto
    int indice=0,w=0;
    while(indice < t_bits)
    {
        if((indice + partes*2) > t_bits)
        {
            if(moduloInt(particiones,2)!=0)
            {
                corrimiento_izquierda(binario, indice, residuo_partes, vueltas);
                indice += partes;
            }
            else{
                corrimiento_derecha(binario, indice, residuo_partes, vueltas);
                indice += partes;
            }
        }
             //cout<<"acamuere "<<w<<endl;
        corrimiento_izquierda(binario, indice,partes, vueltas);
        indice += partes;
        corrimiento_derecha(binario, indice, partes, vueltas);
        indice += partes;
        w++;
    }
    ZZ num;
    num = decimal(&binario, t_bits);
    return num;

}
///desplazamiento simple
void simpleDesplazamientoIzq(vector<bool> *x){
    int sizz = x->size();
    bool last = x->front();
    for(int i=0;i<sizz-1;i++){
        x->at(i)=x->at(i+1);
    }
    x->back()=last;
}
int T56_bits[]={57,49,41,33,25,17,9,1,58,55,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
int T48_bist[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
int vueltas[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

vector<ZZ> DES(void){
    int nrovueltas;
    ZZ respuesta_i;
    vector<bool> originalde64,elde56,elde48,unode28,otrode28;
    vector<ZZ>respuestas;
    ///making the original key
    for(int i=0;i<64;i++){
        originalde64.push_back(moduloInt(rdtsc(),2));
    }
    ///fulling and changing the 56 bits key
    for(int i=0;i<56;i++){
        bool temp;
        temp = originalde64[T56_bits[i]];
        elde56.push_back(temp);
    }
    ///fulling and separating the 56 bits key in two 28 bits keys
    for(int i=0;i<28;i++){
        unode28.push_back(elde56[i]);
        otrode28.push_back(elde56[i+28]);
    }
    ///working for create the final keys
    for(int n=0;n<16;n++){
        nrovueltas=vueltas[n];
        ///gliding of the 28bis keys
        for(int v=0;v<nrovueltas;v++){
            simpleDesplazamientoIzq(&unode28);
            simpleDesplazamientoIzq(&otrode28);
        }
        ///linking the 28 bits keys
        for(int i=0;i<56;i++){
            elde56[i]=unode28[i];
            elde56[i+28]=otrode28[i];
        }
        ///fulling and changing the 48 bits key
        for(int i=0;i<48;i++){
            bool temp;
            temp = elde56[T48_bist[i]];
            elde48.push_back(temp);
        }
        respuesta_i=decimal(&elde48,48);
        respuestas.push_back(respuesta_i);
    }
    return respuestas;
}
