#include "Klient.h"
#include "Magazyn.h"
#include <iostream>


using namespace std;

Klient::Klient(string imie, string nazwisko)
    : Czlowiek(imie, nazwisko) {}


void Klient::zloz_zamowienie(Magazyn* magazyn) {
    // wyswietl dostepne towary z magazynu
    magazyn->wyswietl_dostepne_towary();

    string data;
    cout << "Podaj date zamowienia: ";
    cin >> data;
    cout << endl;

    Zamowienie* zam = new Zamowienie(rand() % 1000 + 1, data, "Zlozone");

    int ilosc, wybor;
    cout << "Ile pozycji chcesz dodac?";
    cin >> ilosc;
    cout << endl;
     
    for (int i = 0; i < ilosc; ++i) {
        cout << "Wybierz indeks towaru (0-...): ";
        cin >> wybor;
        cout << endl;

        int ile;
        cout << "Podaj ilosc: ";
        cin >> ile;
        zam->dodaj_pozycje(magazyn->get_towary()[wybor], ile);
    }
    zam->oblicz_wartosc_zamowienia();
    zamowienia.push_back(zam);
}

void Klient::wyswietl_towary_dostepne(Magazyn* magazyn) {
    magazyn->wyswietl_dostepne_towary();
}

void Klient::wyswietl_swoje_zamowienia() {
    if (zamowienia.empty()) {
        cout << "Brak z³o¿onych zamówieñ." << endl;
        return;
    }

    cout << "Twoje zamówienia:" << endl;
    for (Zamowienie* z : zamowienia) {
        z->wyswietl_zamowienie();
        cout << "-----------------------" << endl;
    }
}

void Klient::odbierz_zamowienie(Zamowienie* z) {
    if (z == nullptr) {
        cout << "Nie znaleziono zamówienia do odbioru." << endl;
        return;
    }

    if (z->get_status() == "Zlozone") {
        z->zmien_status_zamowienia("Odebrane");
        cout << "Zamówienie nr " << z->get_numer() << " zosta³o odebrane." << endl;
    }
    else {
        cout << "Zamówienie nie mo¿e zostaæ odebrane. Aktualny status: " << z->get_status() << endl;
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
}

vector<Zamowienie*>& Klient::get_zamowienia() {
    return zamowienia;
}
