#ifndef SEQOUTFILE_H_INCLUDED
#define SEQOUTFILE_H_INCLUDED

#include <fstream>
#include "common.h"

class SeqOutFile{
public:
    SeqOutFile(std::string fname="");
    void Write( const Tabella &dy);
    ~SeqOutFile() {g.close();}
private:
    std::ofstream g;
};


#endif // SEQOUTFILE_H_INCLUDED
