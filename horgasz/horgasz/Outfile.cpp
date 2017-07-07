#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Horgasz.h"
#include "Outfile.h"

using namespace std;

Outfile::Outfile(string fname)
{
    if ( fname.size()<1 ) {
        cout << "Add meg a kimenet fajl nevet:" ;
        cin >> fname;
    }
    f.open(fname.c_str());
    if ( f.fail() ){
        cerr << "Nem jott letre a fajl!" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

void Outfile::Write(const Horgasz& df)
{
    f<<df;
}
