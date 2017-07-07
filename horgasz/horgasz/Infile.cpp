#include <iostream>
#include <stdlib.h>
#include "Infile.h"

using namespace std;

Infile::Infile(string fname)
{
    if ( fname.size()<1 ) {
        cout<< "Bemenet fajl neve:" ;
        cin>>fname;
    }
    bool hiba;
    do{
        hiba=false;
        f.open(fname.c_str());
        if ( f.fail() ){
            cout<< "Nincs \""<<fname<<"\" nevu fajl!\n"<<endl;
            hiba=true;
            char c;
            cout<<"Megprobalja ujra (i/n)"; cin>>c;
            if(c=='n') {
                cout<<"Viszlat!\n"; exit(2);
            }else{
                f.clear();
                cout<<"Bemenet fajl neve:"; cin>>fname;
            }
        }
    }while(hiba);


}

void Infile::Read(Horgasz &dx, Status &sx)
{
    f>>dx;
    if (!f.eof())
        sx=norm;
    else
        sx=abnorm;
}


