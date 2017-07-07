#include "enor.h"
#include <iostream>
#include <sstream>

using namespace std;

enor::enor(const string& fname)
{
    x.open(fname.c_str());
    if(x.fail()) throw OpenError;
    cout<<fname<<" file feldolgozasa megkezdodott.\n";
}

void enor::first()
{
    next();
}

void enor::next()
{
    read();
    osszegez();
}

void enor::read()
{
    string tmp;
    getline(x,tmp);
    sx = x.fail()? abnorm : norm;
    if(sx==norm){
        dx.id.clear();
        dx.v.clear();
        istringstream s(tmp);
        string z;
        while(s>>z && !isdigit(z[0]))
        {
            dx.id.push_back(z);
        }
        dx.ido=z;
        jegy y;
        while(s>>y.hely>>y.tipus)
        {
            dx.v.push_back(y);
        }
    }
}

void enor::osszegez()
{
    //két összegzés
    dx.sum=0;
    dx.jo=true;
    for(int i=0; i<(int)dx.v.size(); ++i)
    {
        int ar;
        if(dx.v[i].tipus=='G') ar=500;
        else if(dx.v[i].tipus=='D') ar=800;
        else ar=1000;
        dx.sum+=ar;
        dx.jo=dx.jo && dx.v[i].tipus=='D';
    }

}

vetites enor::current() const
{
    return dx;
}

bool enor::end() const
{
    return sx==abnorm;
}

std::ostream& operator<<(std::ostream& out, const vetites& z)
{
    for(int i=0; i<(int)z.id.size(); ++i)
    {
        out<<z.id[i]<<" ";
    }
    out<<z.ido<<" ";
    for(int i=0; i<(int)z.v.size(); ++i)
    {
        out<<z.v[i].hely<<" "<<z.v[i].tipus<<" ";
    }
    out<<"sum="<<z.sum<<" "<<z.jo<<endl;
    return out;
}
