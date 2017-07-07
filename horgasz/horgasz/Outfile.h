#ifndef OUTFILE_H_INCLUDED
#define OUTFILE_H_INCLUDED
#include "Horgasz.h"

class Outfile{
public:
    Outfile(std::string fname="");
    void Write(const Horgasz &df);
    ~Outfile(){ f.close();}
private:
    std::ofstream f;
};


#endif // OUTFILE_H_INCLUDED
