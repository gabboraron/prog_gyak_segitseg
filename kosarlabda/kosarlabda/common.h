#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <vector>

struct Csapat{
    std::string name;
    std::vector<int> dobott;
    std::vector<int> kapott;
};

struct Tabella{
    std::string name;
    int db;
    int nyert;
    int ossz_dobott;
    int ossz_kapott;
};


#endif // COMMON_H_INCLUDED
