#include <fstream>
#include <iostream>
#include "Horgasz.h"

using namespace std;

ifstream& operator>>(ifstream& be, Horgasz& h)
{
    be>>h.Nev;
    for(int i=0;i<h.meret;++i){
        int db;
        be>>db;
        if(db<0){
            cerr<<h.Nev<<" horgasz "<<i+1<<". adata hibas:"<<db<<endl;
            db=0;
        }
        h.Hal[i]=db;
    }
    return be;
}

ofstream& operator<<(ofstream& ki, const Horgasz& h)
{
    ki<<h.Nev<<" ";
    for(int i=0; i<h.meret; ++i)
        ki<<h.Hal[i]<<" ";
    ki<<endl;
    return ki;
}

ostream& operator<<(ostream& ki, const Horgasz& h)
{
    ki<<h.Nev<<" ";
    for(int i=0; i<h.meret; ++i)
        ki<<h.Hal[i]<<" ";
    ki<<endl;
    return ki;
}

int Horgasz::HalFajta() const
{
    int c=0;
    for(int i=0; i<meret; ++i)
        if(Hal[i]>0) c++;
    return c;
}

int Horgasz::HalSzum() const
{
    int s=0;
    for(int i=0; i<meret; ++i)
        s+=Hal[i];
    return s;
}

Horgasz operator+(const Horgasz& h1, const Horgasz& h2){
    Horgasz uj;
    uj.Nev=h1.Nev;
    for (int i=0; i<h1.meret; i++){
    uj.Hal[i]=h1.Hal[i]+h2.Hal[i];
    }
    return uj;
}
