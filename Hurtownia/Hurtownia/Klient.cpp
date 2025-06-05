#include "Klient.h"
#include "Magazyn.h"
#include <iostream>


using namespace std;

Klient::Klient(string imie, string nazwisko)
    : Czlowiek(imie, nazwisko) {}



void Klient::wyswietl_towary_dostepne(Magazyn* magazyn) {
    magazyn->wyswietl_towary("DOSTEPNE");
}


void Klient::odbierz_zamowienie(Zamowienie* z) {
    if (z == nullptr) {
        cout << "Nie znaleziono zamówienia do odbioru." << endl;
        return;
    }

    if (z->get_status() == "Gotowe") {
        z->zmien_status_zamowienia("Odebrane");
        cout << "Zamówienie nr " << z->get_numer() << " zosta³o odebrane." << endl;
    }
    else {
        cout << "Zamówienie nie mo¿e zostaæ odebrane. Aktualny status: " << z->get_status() << endl;
    }

    for (auto& p : z->get_pozycjeZamowienia()) {
        p.get_towar()->zmien_ilosc_zarezerwowanych(-p.get_ilosc());
    }
    
}

void Klient::zwrot_zamowienia(Zamowienie* z) {
    if (z == nullptr) {
        cout << "Nie znaleziono zamówienia do zwrotu." << endl;
        return;
    }

    if (z->get_status() == "Odebrane") {
        z->zmien_status_zamowienia("Zwrócone");
        cout << "Zamówienie nr " << z->get_numer() << " zosta³o zwrócone." << endl;
    }
    else {
        cout << "Zamówienie nie mo¿e zostaæ zwrócone. Status musi byæ 'Odebrane'." << endl;
    }

    for (auto& p : z->get_pozycjeZamowienia()) {
        p.get_towar()->zmien_ilosc_w_magazynie(p.get_ilosc());
    }
}

