#ifndef KLIENT_H
#define KLIENT_H

#include "Czlowiek.h"
#include <string>

using namespace std;

class Zamowienie; 

class Klient : public Czlowiek {
public:
    Klient(string imie, string nazwisko);
    void zloz_zamowienie();
    void wyswietl_towary_dostepne();
    void wyswietl_swoje_zamowienia();
    void odbierz_zamowienie(Zamowienie* z);
    void zwrot_zamowienia(Zamowienie* z);
};

#endif
