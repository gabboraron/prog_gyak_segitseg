#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED
#include <fstream>
#include "Horgasz.h"

enum Status{abnorm, norm};

class Infile{
public:
    Infile(std::string fname="");
    void Read( Horgasz &dx, Status &sx);
    ~Infile() {f.close();}
private:
    std::ifstream f;
};



#endif // INFILE_H_INCLUDED
