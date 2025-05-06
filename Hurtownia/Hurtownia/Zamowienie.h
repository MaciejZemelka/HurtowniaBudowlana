#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "Zamowienie.h"
#include "PozycjeZamowien.h"
#include "Towar.h"
#include <string>

using namespace std;

class Zamowienie {
private:
    int numerZamowienia;
    string dataZamowienia;
    string status;
    vector<PozycjeZamowien> pozycjeZamowienia;
public:
    Zamowienie(int numerZamowienia, string dataZamowienia, string stutus);
    
    void dodaj_pozycje(Towar* T, int ilosc);
};


#endif
