/*
* Feladat:
* Egy szekvenciális input fájlban kosárlabda mérkőzések eredményeit rögzítették.
* A fájl egy sora egy csapat meccseit írja le. A sor formátuma a következő:
* Elsőként a csapat neve van megadva, a név egy vagy több részből áll, szóköz/tab
* választja el a név részeit, tudjuk, hogy a név részei biztosan nem számmal kezdődő
* szövegek
* Utána következnek a meccsek eredményei: saját_pontok-ellenfél_pontjai formában.
* Például:
* Hiros Varos SC utanpotlas 10-20 52-30 34-47
* A fájl sorainak számát nem ismerjük (üres sor nem lehet a fájlban).
* Feladatok:
* A csapatokról készítsük el a következő tabellát (táblázatot) egy output fájlba:
* csapat neve hány_mérkőzést_játszott nyert_mérkőzés vesztett_mérkőzés dobott_pont kapott_pont
* Például:
* Hiros Varos SC utanpotlas 3 1 2 96 97
* Határozzuk meg azt a csapatot, amely a legnagyobb különbséggel nyert meccs büszke tulajdonosa.
* írjuk ki a képernyőre a csapat nevét és a különbséget.
* A csapat eredményeinek beolvasása közben szűrjünk minél több hibát!
*/
#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "seqinfile.h"
#include "seqoutfile.h"

using namespace std;

Tabella Tabellaz(const Csapat& e);
int MaxKul(const Csapat& e);

int main()
{
    cout<<"Kosarlabda bajnoksag\n";
    Csapat e;
    Tabella t;
    Csapat maxelem;
    int max;
    try{
        string fname;
        cout<<"Add meg a fajl nevet:"; cin>>fname;
        SeqInFile f(fname);
        SeqOutFile y;
        f.First();
        if(f.End()){
            cerr<<"Ures a fajl, vagy csupa hibas rekordot tartalmaz!\n";
            exit(2);
        }else{
            //Outputba irás
            e=f.Current();
            t=Tabellaz(e);
            y.Write(t);
            //Maximum Keresés indítása
            max=MaxKul(e);
            maxelem=e;
        }
        f.Next();
        while(!f.End())
        {
            //Outputba irás
            e=f.Current();
            t=Tabellaz(e);
            y.Write(t);
            //Maximum Keresés
            int tmp=MaxKul(e);
            if(tmp>max){
                max=tmp;
                maxelem=e;
            }
            f.Next();
        };
        if(max>=0)
            cout<<"A legnagyobb kulonbseggel nyert:"<<maxelem.name<<" "<<max<<endl;
        else
            cout<<"Senki nem nyert, a legkisebbel vesztes:"<<maxelem.name<<" "<<max<<endl;
    }catch (SeqInFile::InpFileError err){
         cerr<<"Problema van inp.txt fajllal, a feldolgozas leall!\n";
         exit(1);
    }

    return 0;
}

Tabella Tabellaz(const Csapat& e)
{
    Tabella f;
    f.name=e.name;
    f.db=(int)e.dobott.size();
    f.nyert=0;
    f.ossz_dobott=0;
    f.ossz_kapott=0;
    for(int i=0;i<(int)e.dobott.size();i++)
    {
        if(e.dobott[i]>=e.kapott[i]) f.nyert++;
        f.ossz_dobott+=e.dobott[i];
        f.ossz_kapott+=e.kapott[i];
    }
    return f;
}

int MaxKul(const Csapat& e)
{
    if(e.dobott.size()==0){
        cerr<<"Vegzetes nem vart hiba, forduljon a program keszitojehez!\n";
        exit(3);
    }
    int max=e.dobott[0]-e.kapott[0];
    for(int i=1; i<(int)e.dobott.size(); ++i){
        if(e.dobott[i]-e.kapott[i]>max){
            max=e.dobott[i]-e.kapott[i];
        }
    }
    return max;
}
