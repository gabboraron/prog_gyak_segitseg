#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED
#include <fstream>
#include <vector>
#include <string>

enum status{norm,abnorm};

struct jegy{
    char tipus;
    int hely;
};

struct vetites{
    std::vector<std::string> id;
    std::string ido;
    std::vector<jegy> v;
    int sum;
    bool jo;
};

std::ostream& operator<<(std::ostream& out, const vetites&);

class enor{
    public:
        enor(const std::string&);
        enum enorerror{OpenError};
        void first();
        void next();
        vetites current() const;
        bool end() const;
    private:
        std::ifstream x;
        vetites dx;
        status sx;
        void read();
        void osszegez();
};


#endif // ENOR_H_INCLUDED
