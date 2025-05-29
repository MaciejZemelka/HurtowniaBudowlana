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
}

void Zamowienie::zmien_status_zamowienia(string status)
{
}

void Zamowienie::wyswietl_pozycje_zamowienia()
{
}

void Zamowienie::oblicz_wartosc_zamowienia()
{
}
