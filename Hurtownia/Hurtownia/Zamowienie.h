#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "PozycjeZamowien.h"
#include "Towar.h"
#include <string>
#include <vector>

class Klient;

using namespace std;

class Zamowienie {
private:
    int numerZamowienia;
    string dataZamowienia;
    string status;
    vector<PozycjeZamowien> pozycjeZamowienia;
    Klient* klient; 
public:
    Zamowienie(int numerZamowienia, string dataZamowienia, string status, Klient* klient); 
    void dodaj_pozycje(Towar* T, int ilosc);
    void wyswietl_zamowienie();
    void zmien_status_zamowienia(string nowyStatus);
    void wyswietl_pozycje_zamowienia();
    void oblicz_wartosc_zamowienia();

    vector<PozycjeZamowien> get_pozycjeZamowienia() const;
    string get_status() const;
    int get_numer() const;
    Klient* get_klient() const; 
};

#endif
