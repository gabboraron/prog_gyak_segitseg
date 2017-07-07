#ifndef HORGASZ_H_INCLUDED
#define HORGASZ_H_INCLUDED
#include <vector>

class Horgasz{
    private:
        std::string Nev;
        std::vector<int> Hal;
        static const int meret=5;
    public:
        Horgasz() {Hal.resize(meret);}
        friend std::ifstream& operator>>(std::ifstream& be, Horgasz& h);
        friend std::ofstream& operator<<(std::ofstream& ki, const Horgasz& h);
        friend std::ostream& operator<<(std::ostream& ki, const Horgasz& h);
        friend Horgasz operator+(const Horgasz& h1, const Horgasz& h2);
        int HalSzum() const;
        int HalFajta() const;
        std::string GetNev() const { return Nev;}
};


#endif // HORGASZ_H_INCLUDED
