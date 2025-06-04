#include "Magazyn.h"
#include "Towar.h"
#include "Zamowienie.h"
#include "Firma.h"
#include "Klient.h"
#include <iostream>
#include <vector>

using namespace std;

Magazyn::Magazyn(vector<Towar*> towary) {
	this->towary = towary;
}

vector<Zamowienie*>& Klient::get_zamowienia() {
    return zamowienia;
}

void Magazyn::wyswietl_towary(string status) {
    bool znaleziono = false;

    for (const auto& towar : towary) {
        if (towar->get_status() == status) {
            towar->wyswietl_dane_towaru();
            cout << endl;
            znaleziono = true;
        }
    }

    if (!znaleziono) {
        cout << "Brak towarów o statusie: " << status << endl;
    }
}

void Magazyn::usun_towar() {
    if (towary.empty()) {
        cout << "Brak towarów w magazynie do usuniêcia." << endl;
        return;
    }

    cout << "Lista towarów:" << endl;
    for (size_t i = 0; i < towary.size(); ++i) {
        cout << i + 1 << ". ";
        towary[i]->wyswietl_dane_towaru();
        cout << endl;
    }

    int wybor;
    cout << "Podaj numer towaru do usuniêcia: ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > towary.size()) {
        cout << "Nieprawid³owy numer towaru." << endl;
        return;
    }

    delete towary[wybor - 1];
    towary.erase(towary.begin() + (wybor - 1)); 

    cout << "Towar zosta³ usuniêty." << endl;
}

void Magazyn::dodaj_towar() {
    string nazwa, status;
    float cena;
    int iloscZarezerwowana, iloscWMagazynie;

    cout << "Podaj nazwê towaru: ";
    cin >> nazwa;

    cout << "Podaj cenê towaru: ";
    cin >> cena;

    cout << "Podaj status towaru (np. Dostepny): ";
    cin >> status;

    cout << "Podaj iloœæ zarezerwowan¹: ";
    cin >> iloscZarezerwowana;

    cout << "Podaj iloœæ w magazynie: ";
    cin >> iloscWMagazynie;

    Towar* nowy = new Towar(nazwa, cena, status, iloscZarezerwowana, iloscWMagazynie);
    towary.push_back(nowy);

    cout << "Towar dodany pomyœlnie!" << endl;
}

void Magazyn::zloz_zamowienie(Klient k) {
    Towar* t = wybierz_towar();
    if (t == nullptr) {
        cout << "Nie wybrano towaru." << endl;
        return;
    }

    int ilosc;
    cout << "Podaj iloœæ do zamówienia: ";
    cin >> ilosc;

    if (t->get_status() != "Dostepny") { 
        cout << "Towar niedostêpny lub brak wystarczaj¹cej iloœci." << endl;
        return;
    }

    t->zmien_ilosc_zarezerwowanych(ilosc);
    t->zmien_ilosc_w_magazynie(-ilosc);

    time_t teraz = time(0);
    tm* ltm = localtime(&teraz);
    string data = to_string(1900 + ltm->tm_year) + "-" +
        to_string(1 + ltm->tm_mon) + "-" +
        to_string(ltm->tm_mday);

    int numerZamowienia = rand() % 10000 + 1;

    Zamowienie* nowe = new Zamowienie(numerZamowienia, data, "Zlozone");
    nowe->dodaj_pozycje(t, ilosc);

    zamowienia.push_back(nowe);

    cout << "Zamówienie zosta³o z³o¿one pomyœlnie!" << endl;
}

void Magazyn::wyswietl_zamowienia(string status) {
    bool znaleziono = false;

    for (const auto& zamowienie : zamowienia) {
        if (zamowienie->get_status() == status) {
            zamowienie->wyswietl_zamowienie();
            cout << endl;
            znaleziono = true;
        }
    }

    if (!znaleziono) {
        cout << "Brak zamówieñ o statusie: " << status << endl;
    }
}

Towar* Magazyn::wybierz_towar() {
    if (towary.empty()) {
        cout << "Brak towarów w magazynie." << endl;
        return nullptr;
    }

    cout << "Dostêpne towary:" << endl;
    for (size_t i = 0; i < towary.size(); ++i) {
        cout << i + 1 << ". ";
        towary[i]->wyswietl_dane_towaru();
        cout << endl;
    }

    int wybor;
    cout << "Wybierz numer towaru: ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > towary.size()) {
        cout << "Nieprawid³owy numer towaru." << endl;
        return nullptr;
    }

    return towary[wybor - 1];
}

bool czy_towar_dostepny(Towar& t, int ilosc) {
    return t.get_status() == "Dostepny";
}

Zamowienie* Magazyn::wybierz_zamowienie() {
    if (zamowienia.empty()) {
        cout << "Brak dostêpnych zamówieñ." << endl;
        return nullptr;
    }

    cout << "Lista zamówieñ:" << endl;
    for (size_t i = 0; i < zamowienia.size(); ++i) {
        cout << i + 1 << ". Zamówienie nr " << zamowienia[i]->get_numer()
            << " | Status: " << zamowienia[i]->get_status() << endl;
    }

    int wybor;
    cout << "Wybierz numer zamówienia (1-" << zamowienia.size() << "): ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > zamowienia.size()) {
        cout << "Nieprawid³owy wybór." << endl;
        return nullptr;
    }

    return zamowienia[wybor - 1];
}