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
        cout << "Nie znaleziono zam�wienia do odbioru." << endl;
        return;
    }

    if (z->get_status() == "Gotowe") {
        z->zmien_status_zamowienia("Odebrane");
        cout << "Zam�wienie nr " << z->get_numer() << " zosta�o odebrane." << endl;
    }
    else {
        cout << "Zam�wienie nie mo�e zosta� odebrane. Aktualny status: " << z->get_status() << endl;
    }

    for (auto& p : z->get_pozycjeZamowienia()) {
        p.get_towar()->zmien_ilosc_zarezerwowanych(-p.get_ilosc());
    }
    
}

void Klient::zwrot_zamowienia(Zamowienie* z) {
    if (z == nullptr) {
        cout << "Nie znaleziono zam�wienia do zwrotu." << endl;
        return;
    }

    if (z->get_status() == "Odebrane") {
        z->zmien_status_zamowienia("Zwr�cone");
        cout << "Zam�wienie nr " << z->get_numer() << " zosta�o zwr�cone." << endl;
    }
    else {
        cout << "Zam�wienie nie mo�e zosta� zwr�cone. Status musi by� 'Odebrane'." << endl;
    }

    for (auto& p : z->get_pozycjeZamowienia()) {
        p.get_towar()->zmien_ilosc_w_magazynie(p.get_ilosc());
    }
}

