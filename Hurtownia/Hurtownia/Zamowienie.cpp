#include "Zamowienie.h"
#include <iostream>
using namespace std;

Zamowienie::Zamowienie(int numerZamowienia, string dataZamowienia, string status, Klient* klient)
    : numerZamowienia(numerZamowienia), dataZamowienia(dataZamowienia), status(status), klient(klient) {
}

void Zamowienie::dodaj_pozycje(Towar* T, int ilosc) {
    pozycjeZamowienia.push_back(PozycjeZamowien(T, ilosc));
}

void Zamowienie::wyswietl_zamowienie() {
    cout << "Zamowienie nr: " << numerZamowienia << " Data: " << dataZamowienia << " Status: " << status << endl;
    wyswietl_pozycje_zamowienia();
    oblicz_wartosc_zamowienia();
}

void Zamowienie::zmien_status_zamowienia(string nowyStatus) {
    status = nowyStatus;
}

void Zamowienie::wyswietl_pozycje_zamowienia() {
    for (auto& p : pozycjeZamowienia) {
        p.wyswietl_pozycje();
    }
}


void Zamowienie::oblicz_wartosc_zamowienia() {
    float suma = 0;
    for (auto& p : pozycjeZamowienia) {
        suma += p.get_ilosc() * p.get_towar()->get_cena();
    }
    cout << "Laczna wartosc zamowienia: " << suma << "zl" << endl;
}

string Zamowienie::get_status() const {
    return status;
}

int Zamowienie::get_numer() const {
    return numerZamowienia;
}

Klient* Zamowienie::get_klient() const {
    return klient;
}

vector<PozycjeZamowien> Zamowienie::get_pozycjeZamowienia() const {
    return pozycjeZamowienia;
}
