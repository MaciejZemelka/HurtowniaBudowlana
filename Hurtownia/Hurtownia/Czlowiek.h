#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <string>
using namespace std;


class Czlowiek {
private:
    string imie;
    string nazwisko;

public:
    string get_imie();
    void wypisz_dane();
    Czlowiek(string imie, string nazwisko);
};

#endif