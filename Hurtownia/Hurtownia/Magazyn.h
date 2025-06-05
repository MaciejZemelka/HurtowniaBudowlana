#ifndef MAGAZYN_H
#define MAGAZYN_H

#include "Towar.h"
#include "Zamowienie.h"
#include "Firma.h"
#include <string>
#include <vector>

class Klient;

using namespace std;

class Magazyn
{
private:
    Firma* firma;
    vector<Towar*> towary;
    vector<Zamowienie*> zamowienia;

public:
    Magazyn(vector<Towar*> towary);

    void wyswietl_towary(string status);
    void usun_towar();
    void dodaj_towar();
    void zloz_zamowienie(Klient* k); 
    void wyswietl_zamowienia(string status, Klient* k = nullptr); 
    Towar* wybierz_towar(string status);
    bool czy_towar_dostepny(Towar t, int ilosc);
    Zamowienie* wybierz_zamowienie(string status);
    void przygotuj_zamowienie(Zamowienie* z);
};

#endif
