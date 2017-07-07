#ifndef SEQINFILE_H_INCLUDED
#define SEQINFILE_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>

#include "common.h"

enum Status{abnorm, norm};

class SeqInFile
{
    public:
        enum InpFileError{MissingFile,MissingResult,WrongResultFormat};
        SeqInFile(std::string fname="");
        void First();
        void Next();
        bool End() const { return sf==abnorm;}
        Csapat Current() const { return elem; }
    private:
        std::ifstream f;
        Csapat elem;
        Status sf;
        std::string sor;
        void read();
};


#endif // SEQINFILE_H_INCLUDED
