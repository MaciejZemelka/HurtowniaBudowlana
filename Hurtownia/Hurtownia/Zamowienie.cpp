#include "Zamowienie.h"
#include <iostream>
using namespace std;

Zamowienie::Zamowienie(int numerZamowienia, string dataZamowienia, string stutus) :
    numerZamowienia(numerZamowienia), dataZamowienia(dataZamowienia), status(status) {};

void Zamowienie::dodaj_pozycje(Towar* T, int ilosc) {
    pozycjeZamowienia.push_back(PozycjeZamowien(T, ilosc));
}

void Zamowienie::wyswietl_zamowienie()
{
    cout << "Zamowienie nr: " << this->numerZamowienia << " Data: " << this->dataZamowienia << " Status: " << this->status << endl;
    wyswietl_pozycje_zamowienia();
    oblicz_wartosc_zamowienia();
}

void Zamowienie::zmien_status_zamowienia(string nowyStatus)
{
    status = nowyStatus;
}

void Zamowienie::wyswietl_pozycje_zamowienia()
{
    for (auto& p : pozycjeZamowienia) {
        p.wyswietl_pozycje();
    }
}

void Zamowienie::oblicz_wartosc_zamowienia()
{
    float suma = 0;
    for (auto& p : pozycjeZamowienia) {
        suma += p.get_ilosc() * p.get_towar()->get_cena();
    }
    cout << "Laczna wartosc zamowienia: " << suma << "zl" << endl;
}
