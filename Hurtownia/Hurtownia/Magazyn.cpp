#include "Magazyn.h"
#include <iostream>
#include <vector>
#include "Klient.h"
using namespace std;

Magazyn::Magazyn(vector<Towar*> towary) {
    this->towary = towary;
}

void Magazyn::wyswietl_towary(string status) {
    bool znaleziono = false;
    cout << "Lista dostepnych towarow: \n";
    for (const auto& towar : towary) {
        if (towar->get_status() == status || status == "") {
            towar->wyswietl_dane_towaru();
            cout << endl;
            znaleziono = true;
        }
    }
    if (!znaleziono) {
        cout << "Brak towar�w o statusie: " << status << endl;
    }
    cout << endl;
}

void Magazyn::usun_towar() {
    if (towary.empty()) {
        cout << "Brak towar�w w magazynie do usuni�cia." << endl;
        return;
    }

    cout << "Lista towar�w:" << endl;
    for (size_t i = 0; i < towary.size(); ++i) {
        cout << i + 1 << ". ";
        towary[i]->wyswietl_dane_towaru();
        cout << endl;
    }

    int wybor;
    cout << "Podaj numer towaru do usuni�cia: ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > towary.size()) {
        cout << "Nieprawid�owy numer towaru." << endl;
        return;
    }

    delete towary[wybor - 1];
    towary.erase(towary.begin() + (wybor - 1));

    cout << "Towar zosta� usuni�ty." << endl;
}

void Magazyn::dodaj_towar() {
    string nazwa, status;
    float cena;
    int iloscZarezerwowana, iloscWMagazynie;

    cout << "Podaj nazw� towaru: ";
    cin >> nazwa;

    cout << "Podaj cen� towaru: ";
    cin >> cena;

    cout << "Podaj status towaru (np. Dostepny): ";
    cin >> status;

    cout << "Podaj ilo�� zarezerwowan�: ";
    cin >> iloscZarezerwowana;

    cout << "Podaj ilo�� w magazynie: ";
    cin >> iloscWMagazynie;

    Towar* nowy = new Towar(nazwa, cena, status, iloscZarezerwowana, iloscWMagazynie);
    towary.push_back(nowy);

    cout << "Towar dodany pomy�lnie!" << endl;
}

void Magazyn::zloz_zamowienie(Klient* k) {
    Towar* t = wybierz_towar("Dostepny");
    if (t == nullptr) {
        cout << "Nie wybrano towaru." << endl;
        return;
    }

    int ilosc;
    cout << "Podaj ilo�� do zam�wienia: ";
    cin >> ilosc;

    if (t->get_status() != "Dostepny" || t->get_iloscWMagazynie() < ilosc) {
        cout << "Towar niedost�pny lub brak wystarczaj�cej ilo�ci." << endl;
        return;
    }

    t->zmien_ilosc_zarezerwowanych(ilosc);
    t->zmien_ilosc_w_magazynie(-ilosc);

    time_t teraz = time(0);
    tm ltm;
    localtime_s(&ltm, &teraz);
    string data = to_string(1900 + ltm.tm_year) + "-" +
        to_string(1 + ltm.tm_mon) + "-" +
        to_string(ltm.tm_mday);

    int numerZamowienia = rand() % 10000 + 1;

    Zamowienie* nowe = new Zamowienie(numerZamowienia, data, "Zlozone", k);
    nowe->dodaj_pozycje(t, ilosc);

    zamowienia.push_back(nowe);

    cout << "Zam�wienie zosta�o z�o�one pomy�lnie!" << endl;
}

void Magazyn::wyswietl_zamowienia(string status, Klient* k) {
    bool znaleziono = false;

    for (const auto& zamowienie : zamowienia) {
        if (k == nullptr && status == "") {
            zamowienie->wyswietl_zamowienie();
            cout << endl;
            znaleziono = true;
        }
        else if (zamowienie->get_status() == status && k == nullptr) {
            zamowienie->wyswietl_zamowienie();
            cout << endl;
            znaleziono = true;
        }
        else if (k == zamowienie->get_klient()) {
            zamowienie->wyswietl_zamowienie();
            cout << endl;
            znaleziono = true;
        }
        else {
            cout << "inny przypadek spr wyswietl_zamoeinia";
        }
    }

    if (!znaleziono) {
        cout << "Brak zam�wie� o statusie: " << status << endl;
    }
}

Towar* Magazyn::wybierz_towar(string status) {
    if (towary.empty()) {
        cout << "Brak towar�w w magazynie." << endl;
        return nullptr;
    }

    cout << "Dost�pne towary:" << endl;
    for (size_t i = 0; i < towary.size(); ++i) {
        if (towary[i]->get_status() == status || status == "") {
            cout << i + 1 << ". ";
            towary[i]->wyswietl_dane_towaru();
            cout << endl;
        }
    }

    int wybor;
    cout << "Wybierz numer towaru: ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > towary.size()) {
        cout << "Nieprawid�owy numer towaru." << endl;
        return nullptr;
    }

    return towary[wybor - 1];
}

bool czy_towar_dostepny(Towar& t, int ilosc) {
    return t.get_status() == "Dostepny";
}

void Magazyn::przygotuj_zamowienie(Zamowienie* z) {
    z->zmien_status_zamowienia("Gotowe");
}
Zamowienie* Magazyn::wybierz_zamowienie(string status) {
    if (zamowienia.empty()) {
        cout << "Brak dost�pnych zam�wie�." << endl;
        return nullptr;
    }

    int zam = 0;

    cout << "Lista zam�wie�:" << endl;
    for (size_t i = 0; i < zamowienia.size(); ++i) {
        if (zamowienia[i]->get_status() == status) {
            zam++;
            cout << i + 1 << ". Zam�wienie nr " << zamowienia[i]->get_numer()
                << " | Status: " << zamowienia[i]->get_status() << endl;
        }
       
    }

    if (zam == 0) {
        cout << "Brak dost�pnych zam�wie�." << endl;
        return nullptr;
    }

    int wybor;
    cout << "Wybierz numer zam�wienia (1-" << zamowienia.size() << "): ";
    cin >> wybor;

    if (wybor < 1 || static_cast<size_t>(wybor) > zamowienia.size()) {
        cout << "Nieprawid�owy wyb�r." << endl;
        return nullptr;
    }

    return zamowienia[wybor - 1];
}
