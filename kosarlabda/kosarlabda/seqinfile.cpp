#include "seqinfile.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

SeqInFile::SeqInFile(string fname)
{
    if(fname.size()<1) fname="inp.txt";
    f.open(fname.c_str());
    if(f.fail()){
        throw MissingFile;
    }
}

void SeqInFile::First()
{
    Next();
}

void SeqInFile::Next()
{
    bool hiba;
    do{
        hiba=false;
        try{
            read();
        }catch(SeqInFile::InpFileError err){
            cerr<<"Hibas rekord:"<<sor<<endl;
            switch(err){
                case SeqInFile::MissingResult:
                    cerr<<"Nincs eredmenye a csapatnak.\n";
                    break;
                case SeqInFile::WrongResultFormat:
                    cerr<<"Rossz az eredmeny formatuma.\n";
            }
            hiba=true;
            cerr<<"A rekord kimarad a feldolgozasbol!\n\n";
        }
    }while(hiba && !End());
}



void SeqInFile::read()
{
    f.clear();
    getline(f,sor);
    //cout<<sor<<endl;
    if(!f.fail()){
        sf = norm;
        istringstream ss(sor);

        // Név beolvasása, amíg számjeggyel vagy '-' jellel nem kezdõdik a szó
        string str;
        elem.name = "";
        for(ss >> str; !ss.fail()&& !(('0'<=str[0] && str[0]<='9') || str[0]=='-'); ss >> str){
            elem.name += str + " ";
        }
        //isdigit is jó megoldás:
        /*for(ss >> str; !ss.fail()&& !(isdigit(str[0]) || str[0]=='-'); ss >> str){
            elem.name += str + " ";
        }*/
        //cout<<elem.name<<" ";

        //Ha itt vége, akkor a csapat neve után nem jöttek eredmények
        if(ss.fail()) throw MissingResult;

        // Eredmények beolvasása
        elem.dobott.resize(0);
        elem.kapott.resize(0);
        for(; !ss.fail(); ss >> str){
            unsigned pos=str.find("-");
            if(pos==string::npos || pos==0 || pos==str.size()-1) throw WrongResultFormat;
            int dob=atoi(str.substr(0,pos).c_str());
            int kap=atoi(str.substr(pos+1,str.size()-pos-1).c_str());
            //cout<<dob<<" "<<kap<<" ";
            elem.dobott.push_back(dob);
            elem.kapott.push_back(kap);
        }
        //cout<<endl;
    } else sf = abnorm;
}
