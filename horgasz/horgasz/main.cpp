//Feladat: egy horgászversenyen az elődöntőt két menetben bonyolították.
//Mindkét menetben 5 féle halat kellett fogni, a két bemenet fájl az elődöntők eredményeit tatalmazza:
//horgász neve fogott halak száma (5 egész formájában), például:
//Bela 2 3 5 0 4
//A bemenet fájlok név szerint szigorúan monoton növekedők.
//Akik mindkét elődöntőben részt vettek, azok eredménye összeadódik, akik csak az egyiken,
//vagy csak a másikon, azok azzal az eredménnyel juthatnak tovább.
//Készítsük el a továbbjutók és a kiesők listáját.
//Továbbjutnak azok, aki legalább 3 féle halat fogtak, és összesen legalább 10 halat fogtak.
//A kimenet fájlokba a horgász nevét, és az összteljesítményét kell kiírni.

#include <iostream>
#include <vector>
#include <iomanip>
#include "Horgasz.h"
#include "Infile.h"
#include "Outfile.h"

using namespace std;

int main()
{
    cout << "Horgaszverseny-rendezett fajlok osszefuttatasa" << endl;
    cout<<"Elso fordulo\n";
    Infile x1;
    cout<<"Masodik fordulo\n";
    Infile x2;
    Outfile y("Tovabbjutottak.txt");
    Outfile z("Kiesok.txt");
    Horgasz dx1,dx2;
    Status sx1,sx2;
    x1.Read(dx1,sx1); x2.Read(dx2,sx2);
    cout<<"\n***Feldolgozas sorrendje***\n";
    while (sx1==norm || sx2==norm){
        if(sx1==norm && sx2==norm && dx1.GetNev()==dx2.GetNev()){
            Horgasz dx=dx1+dx2;
            cout<<"Egyenlok "<<dx<<endl;
            if(dx.HalSzum()>9 && dx.HalFajta()>2)
                y.Write(dx); else z.Write(dx);
            x1.Read(dx1,sx1); x2.Read(dx2,sx2);
        }
        else if(sx2==abnorm || (sx1==norm && dx1.GetNev()<dx2.GetNev())){
            cout<<"Elso     "<<dx1<<endl;
            if(dx1.HalSzum()>9 && dx1.HalFajta()>2)
                y.Write(dx1); else z.Write(dx1);
            x1.Read(dx1,sx1);
        }
        else if(sx1==abnorm || (sx2==norm && dx2.GetNev()<dx1.GetNev())){
            cout<<"Masodik  "<<dx2<<endl;
            if(dx2.HalSzum()>9 && dx2.HalFajta()>2)
                y.Write(dx2); else z.Write(dx2);
            x2.Read(dx2,sx2);
        }else {
            cout<<"Itt nem szabad jarnia!\n"; //csak a teszteles miatt
        }
    }
    cout<<"***********Kesz*************\n";
    return 0;
}
