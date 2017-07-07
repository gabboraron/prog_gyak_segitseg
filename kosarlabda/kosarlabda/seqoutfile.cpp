#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "seqoutfile.h"

//Feladat:    Eredmány fájl megnyitása
//Bemenet:    string fname - szöveges állomány neve
//Kimenet:    ofstream g   - létrehozott szekvenciális output fájl
SeqOutFile::SeqOutFile(std::string fname)
{
    if ( fname.size()<1 ) {
        std::cout<< "Add meg a kimenet fajl nevet:" ;
        std::cin>>fname;
    }
    g.open(fname.c_str());
    if ( g.fail() ){
        std::cout<< "Nem sikerult letrehozni a fajlt" <<std::endl;
        char ch; std::cin>>ch;
        exit(2);
    }
}

//Feladat:    Válaszoló adatainak kiírása a szekvenciális outputfájlba
//Bemenet:    Tabella dy   - válaszoló adatai
//            ofstream g  - felmérés adatait tartalmazó szekvenciális outputfájl
//Kimenet:    ofstream g  - felmérés adatait tartalmazó szekvenciális outputfájl
void SeqOutFile::Write(const Tabella &dy)
{
    g<<std::setw(30)<<dy.name
    <<std::setw(5)<<dy.db
    <<std::setw(5)<<dy.nyert
    <<std::setw(5)<<dy.db-dy.nyert
    <<std::setw(6)<<dy.ossz_dobott
    <<std::setw(6)<<dy.ossz_kapott
    <<"\n";
}

