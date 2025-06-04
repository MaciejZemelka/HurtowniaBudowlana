#ifndef KLIENT_H
#define KLIENT_H

#include "Czlowiek.h"
#include <string>
#include "Zamowienie.h"
#include "Magazyn.h"
using namespace std;


class Klient : public Czlowiek {
    vector<Zamowienie*> zamowienia;
public:
    Klient(string imie, string nazwisko);
    void zloz_zamowienie(Magazyn* magazyn);
    void wyswietl_towary_dostepne(Magazyn* magazyn);
    void wyswietl_swoje_zamowienia();
    void odbierz_zamowienie(Zamowienie* z);
    void zwrot_zamowienia(Zamowienie* z);
    vector<Zamowienie*>& get_zamowienia();
};

#endif
