#include "Trans.h"
int mod(int a , int b){
	int q,r;
	q = a/b;
	r = a - (q*b);
	if (r<0){
		r=r+b;
	}
	return r;
}

Trans::Trans(int clave)
{
    this->clave = clave;
}

Trans::~Trans()
{
    //dtor
}

void Trans::llenar(string *frase){
    int x=(*frase).size();
    while(mod(x,clave-1)!=0){
        (*frase)+='°';
        x++;
    }
    (*frase)+='°';
}

string Trans::transponer(string frase){
    llenar(&frase);
    string tay;
    int s1=2*(clave-1) , s2=0,f=0,pos=0;
    int sz=frase.size();

    while(f<clave){
        tay+=frase[pos];
        while(pos<=sz-1){
            pos=pos+s1;
            if(pos<=sz-1 and s1!=0)
                tay+=frase[pos];
            pos=pos+s2;
            if(pos<=sz-1 and s2!=0)
                tay+=frase[pos];
           /// cout<<tay<<endl;
        }
        s1-=2;s2+=2;
        f++;
        pos=f;
    };
    return tay;
    /*while(j< sz-1 and f<clave-1){
        if(pos >= (sz-1) and f<clave-1){
            f++;
            s1-=2;s2+=2;
            pos=f;
            tay+=frase[pos];
            j++;
            }
        pos+=s1;
        if(s1!=0){
            tay+=frase[pos];}
        j++;
        pos+=s2;
        if(s2!=0 ){
            tay+=frase[pos];}

   ///     cout<<tay.size()<<" "<< j<<" "+tay<<endl;
    }
    return tay;*/
    }

string Trans::poner(string fresa){
    string tay;
    int s1=2*(clave-1) , s2=0 , f=0 , pos=0 , i=0;
    int sz=fresa.size();

    for(int o = 0; o < sz;o++)
        tay+="-";

    while(f<clave){
        tay[pos]=fresa[i];
        while(pos<=sz-1){
            pos=pos+s1;
            if(pos<=sz-1 and s1!=0){
                i++;
                tay[pos]=fresa[i];}
            pos=pos+s2;
            if(pos<=sz-1 and s2!=0){
                i++;
                tay[pos]=fresa[i];}
            ///cout<<tay<<endl;
        }
        s1-=2;s2+=2;
        f++;
        pos=f;
        i++;
    };
    return tay;

   /* string tay;
    int j=0, s1=2*(clave-1) , s2=0,f=0,pos=0;
    int sz=s,i=0;
    bool entro=false;

    for(int o = 0; o < sz;o++)
        tay+="-";

    tay[pos]=fresa[i];
    i++;
    while(j< sz-1){
        if (pos>=sz -1 ){
            entro = true;
            if(f<clave-1)
                f+=1;
            pos=f;
            if(s1!=0){
                s1-= 2; s2+=2;}
            tay[pos]=fresa[i];i++;
            cout<<j<<" "<<s1<<" "<<s2<<" "<<pos<<" "<<i<<'\t'+tay+'\n';
            //i++;
        }
        pos+=s1;
        if((s1 != 0) and (pos < sz)){
            tay[pos]=fresa[i];
            cout<<j<<" "<<s1<<" "<<s2<<" "<<pos<<" "<<i<<'\t'+tay+'\n';
        }
        pos+=s2;
        if((s2 != 0) and (pos <sz)){
            tay[pos] = fresa[i+1];i++;
            cout<<j<<" "<<s1<<" "<<s2<<" "<<pos<<" "<<i<<'\t'+tay+'\n';
        }
        if(entro == true){
            entro =false;}
        else
            i++;
        j++;

    }
    return tay;*/

}
