#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    cout << "Mozi" << endl;
    string fname;
    bool hiba;
    do{
        try{
            hiba=false;
            cout<<"Add meg a fajl nevet: ";
            cin>>fname;
            enor t(fname);
            //két összegzés
            bool l=false;
            //for(t.first(); !t.end(); t.next())
            //Ha az ures fajlra hibat kell jelezni
            t.first();
            if(t.end())
            {
                cout<<"Ures a fajl, nem lehet feldolgozni!\n";
                hiba=true;
                break;
            }
            for(;!t.end(); t.next())
            {
                vetites q=t.current();
                //cout<<"*****"<<q;
                cout<<q.ido<<" "<<q.id[q.id.size()-1]<<" "<<q.sum;
                if(q.jo) cout<<" (csak diak)\n"; else cout<<endl;
                l= l || q.jo;
            }
            if(l)
                cout<<"Volt olyan vetites, amelyikre csak diakok valtottak jegyet\n";
            else
                cout<<"Nem volt olyan vetites, amelyikre csak diakok valtottak jegyet\n";
        }catch(enor::enorerror err)
        {
            if(err==enor::OpenError)
            {
                cerr<<fname<<" nem nyithato meg!\n";
                hiba=true;
            }
        }
    }while(hiba);
    return 0;
}
