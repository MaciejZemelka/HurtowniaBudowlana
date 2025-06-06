#ifndef KLIENT_H
#define KLIENT_H

#include "Czlowiek.h"
#include <string>
#include "Zamowienie.h"
class Magazyn;
using namespace std;


class Klient : public Czlowiek {
public:
    Klient(string imie, string nazwisko);

    void zloz_zamowienie(Magazyn* magazyn);
    void wyswietl_towary_dostepne(Magazyn* magazyn);
    void wyswietl_swoje_zamowienia();
    void odbierz_zamowienie(Zamowienie* z);
    void zwrot_zamowienia(Zamowienie* z);
 
};

#endif
