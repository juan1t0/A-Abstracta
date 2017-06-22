#include "Funtions.h"

ZZ raizPrimitiva(ZZ nro){
    ZZ q=(nro-1)/2;
    ZZ g;
    ZZ dos=to_ZZ(2);
    for(int i=1;i<nro-1;i++){
        g = generadorAleatorio(17,32,8,11);
        while(g<2 && g>nro-1)
            g = generadorAleatorio(17,32,8,11);
        if((potenciaModular(g,dos,nro)!=1) && (potenciaModular(g,q,nro)!= 1))
            return g;
    }
    return g;
}
ZZ modulozz(ZZ a,ZZ b){
    ZZ r;
    r=a-((a/b)*b);
    if(r<0)
        r+=b;
    return r;
}
int moduloint(int a, int b){
    int r;
    r=a-((a/b)*b);
    if(r<0)
        r+=b;
    return r;
}
ZZ mcdzz(ZZ a,ZZ b){
    ZZ r=modulozz(a,b);
    while(r>0){
        a=b;
        b=r;
        r=modulozz(a,b);
    }
    return b;
}
int mcdint(int a, int b){
    int r=moduloint(a,b);
    while(r>0){
        a=b;
        b=r;
        r=moduloint(a,b);
    }
    return b;
}
ZZ inversoMultiplicativoZZ(ZZ a,ZZ b){
    ZZ b0 = b, temp, q;
    ZZ a0 = to_ZZ(0);
    ZZ a1 = to_ZZ(1);
    while (a > 1){
        if(b==0)
            cout<<"/ zero"<<endl;
        q = a / b;
        temp = b;
        b = modulozz(a,b);
        a = temp;
        temp = a0;
        a0 = a1 - q * a0;
        a1 = temp;
    }
    if (a1 < 0)
        a1 += b0;
    return a1;
}
ZZ valorAbsoluto(ZZ a){
    if(a >= 0)
        return a;
    else
        return a*(-1);
}
ZZ potenciaModular(ZZ n1,ZZ n2,ZZ mod){
    ZZ resultado=to_ZZ(1);
	while(n2>0){
		if(modulozz(n2,to_ZZ(2))==1)
			resultado=modulozz(n1*resultado,mod);
		n2=n2/2;
		n1=modulozz(n1*n1,mod);
	}
	return resultado;
}
ZZ stringToZZ(string nro){
    ZZ number(INIT_VAL, nro.c_str());
    return number;
}
string zzToString(ZZ nro){
    stringstream buffer;
    buffer << nro;
    return buffer.str();
}
bool Fermat(int num,ZZ primo){
    ZZ a,c;
    c=1;
    if(primo==2){
        return 1;
    }
    for(int i = 0;i< num;i++){
        a = generadorAleatorio(16,512,16,8);
        if(a>=primo){
            a=modulozz(a,primo);
        }
        if(potenciaModular(a,(primo-c),primo)==1){
            return 1;
        }
    }
    return 0;
}
int rdtsc(){
    __asm__ __volatile__("rdtsc");
}
void swag(int a1,int a2,vector<bool> *b){
    bool temp= b->at(a1);
    b->at(a1)=b->at(a2);
    b->at(a2)=temp;
}
void corrimientoAlaDerecha(vector<bool> *b,int i,int element,int vueltas){
    int pos_A= moduloint(rdtsc(),element);
    bool ultimoBit = b->at((element*2) -1);
    for(int k=vueltas;k>0;k--){
        for(int l=(element*2)-1-i;l>=element;l--)
            swag(l,l+1,b);
    }
    bool ex = b->at(pos_A + element) ^ ultimoBit;
    b->at(element)=ex;
}
void corrimientoAlaIzquierda(vector<bool> *b,int i,int element,int vueltas){
    int pos_A= moduloint(rdtsc(),element-1);
    bool primerBit = b->at(0);
    for(int k=vueltas;k>0;k--){
        for(int l=0;l<element-1-i;l++)
            swag(l,l+1,b);
    }
    bool ex =primerBit ^ b->at(pos_A);
    b->at(element-1)=ex;
}
ZZ toDecimal(vector<bool> *b,int cantBits){
    ZZ nro=to_ZZ(0);
    int e=0;
    for(int i=cantBits -1;i>=0;i--){
        if(b->at(i)==1)
            (nro += power2_ZZ(e));
        else
            (nro += to_ZZ(0));
        e+=1;
    }
    return nro;
}
ZZ generadorAleatorio(int seed,int cantBits,int partes,int vueltas){
    vector <bool>binario;
    bool aleatorio_bit_seed= 0;
    for(int i = 0; i < cantBits; i++)
        binario.push_back(0);

    int s=0;   //j pos vector ,s recorre
    for(int i = 0 ; i<seed; i++)
    {
        aleatorio_bit_seed= moduloint(rdtsc(),2);
        binario[i]= aleatorio_bit_seed;
    }
    if(binario[0]==0)
            binario[0]=1;
    for(int i=seed; i < cantBits; i++)
    {
        binario[i] = binario[s] ^ binario[s+1]; //concatenar xor
        s++;
    }
    int parts=cantBits/partes; //cuantos bits tiene cada parte
    int residuo_partes= moduloint(cantBits,partes); //por si no es exacto
    int indice=0,w=0;
    while(indice < cantBits)
    {

        if((indice + parts*2) > cantBits)
        {
            if(moduloint(partes,2)!=0)
            {
                corrimientoAlaIzquierda(&binario, indice, residuo_partes, vueltas);
                indice += parts;
            }
            else{
                corrimientoAlaDerecha(&binario, indice, residuo_partes, vueltas);
                indice += parts;
            }
        }
        corrimientoAlaIzquierda(&binario,indice,parts,vueltas);
        indice += parts;
        corrimientoAlaDerecha(&binario, indice, parts, vueltas);
        indice += parts;
        w++;
    }
    ZZ num;
    num = toDecimal(&binario, cantBits);
    return num;
}

void simpleDesplazamientoIzq(vector<bool> *b){
    int sizz = b->size();
    bool last = b->front();
    for(int i=0;i<sizz-1;i++)
        b->at(i)=b->at(i+1);

    b->back()=last;
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
        originalde64.push_back(moduloint(rdtsc(),2));
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
        respuesta_i=toDecimal(&elde48,48);
        respuestas.push_back(respuesta_i);
    }
    return respuestas;
}
