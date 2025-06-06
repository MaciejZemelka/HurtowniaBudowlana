#include <iostream>
#include "Klient.h"
#include "Towar.h"
#include "Magazyn.h"

#include <cstdlib>

using namespace std;

int main() {
    

    Towar* T1 = new Towar("Lopata", 50.99, "Dostepny", 0, 100);
    Towar* T2 = new Towar("Mlot", 29.99, "Dostepny", 0, 100);
    Towar* T3 = new Towar("Cement 10kg", 10.99, "Dostepny", 0, 100);
    Towar* T4 = new Towar("Cegly 100szt", 250, "Nie dostepny", 0, 0);
    vector<Towar*> towary;
    towary.push_back(T1); 
    towary.push_back(T2);
    towary.push_back(T3);
    towary.push_back(T4);
    vector<Zamowienie*> zamowienia;


    Magazyn* M1 = new Magazyn(towary, zamowienia);

   // M1->wyswietl_wszystkie_towary();
   

    Klient* klient = new Klient("Jan", "Nowak");
    int osoba;
    int akcja = -1;
    bool program = true;
    cout << "============================";
    cout << "Witaj w hurtowni materialow budowlanych";
    cout << "============================\n\n";
    
    while (program) {
        system("cls");
        cout << "Kim dzisiaj jestes?:\n";
        cout << "1. klient\n";
        cout << "2. pracownik\n";
        cout << "3. kierownik\n";
        cout << "0. wyjście z programu\n";
        cout << "Wybrana akcja: ";
        cin >> osoba;
        akcja = -1;
        system("cls");
        switch (osoba) {
        case 1:
            while (akcja != 0) {
                cout << "Wybierz akcje:\n";
                cout << "1. Wyswietl liste dostepnych towarow\n";
                cout << "2. Zamow produkt\n";
                cout << "3. Sprawdź stan zamowienia\n";
                cout << "4. Odbierz zamowienie\n";
                cout << "5. Zwrot zamowienia\n";
                cout << "0. wyjscie do wyboru\n";
                cout << "Wybrana akcja: ";
                cin >> akcja;
                system("cls");
                switch (akcja) {
                case 1:
                    system("cls");


                    M1->wyswietl_towary("Dostepny");
                    cout << endl << endl;
                    break;
                case 2:
                    system("cls");
                    M1->zloz_zamowienie(klient);
                    cout << endl << endl;
                    break;
                case 3:
                    system("cls");
                    M1->wyswietl_zamowienia("", klient);
                    cout << endl << endl;
                    break;
                case 4:
                {
                    system("cls");
                    Zamowienie* z = M1->wybierz_zamowienie("Gotowe");
                    klient->odbierz_zamowienie(z);
                    cout << endl << endl;
                    break;
                }
                case 5:
                {
                    system("cls");
                    Zamowienie* z = M1->wybierz_zamowienie("Odebrane");
                    klient->zwrot_zamowienia(z);
                    cout << endl << endl;
                    break;
                }
                default:
                    break;
                }

            }
            break;
        case 2:
            while (akcja != 0) {
                cout << "Wybierz akcje:\n";
                cout << "1. Wyswietl liste towarow\n";
                cout << "2. Wyswietl liste zamowien\n";
                cout << "3. Zapakuj zamowienie\n";
                cout << "4. Uzupelnij stan magazynowy\n";
                cout << "0. wyjscie do wyboru\n";
                cout << "Wybrana akcja: ";
                cin >> akcja;
                switch (akcja) {
                case 1:
                    system("cls");
                    M1->wyswietl_towary("");
                    cout << endl << endl;
                    break;
                case 2:
                    system("cls");
                    M1->wyswietl_zamowienia("", nullptr);
                    cout << endl << endl;
                    break;
                case 3:
                {
                    system("cls");
                    Zamowienie* z = M1->wybierz_zamowienie("Zlozone");
                    if (z != nullptr) {
                        M1->przygotuj_zamowienie(z);
                    }
                    cout << endl << endl;
                    break;
                }
                case 4:
                {
                    system("cls");
                    Towar* t = M1->wybierz_towar("");
                    int oIle;
                    cout << "\n Zmien stan magazynowy towaru \n";
                    t->wyswietl_dane_towaru();
                    cout << "Podaj ilosc: \n";
                    cin >> oIle;
                    t->zmien_ilosc_w_magazynie(oIle);
                    cout << endl << endl;
                    break;
                }
                default:
                    break;
                }

            }
            break;
        case 3:
            while (akcja != 0) {
                cout << "Wybierz akcje:\n";
                cout << "1. Wyswietl liste towarow\n";
                cout << "2. Wyswietl liste zamowien\n";
                cout << "3. Zapakuj zamowienie\n";
                cout << "4. Uzupelnij stan magazynowy\n";
                cout << "5. Dodaj towar\n";
                cout << "6. Usun towar\n";
                cout << "0. wyjscie do wyboru\n";
                cout << "Wybrana akcja: ";
                cin >> akcja;
                switch (akcja) {
                case 1:
                    system("cls");
                    M1->wyswietl_towary("");
                    cout << endl << endl;
                    break;
                case 2:
                    system("cls");
                    M1->wyswietl_zamowienia("", nullptr);
                    cout << endl << endl;
                    break;
                case 3:
                {
                    system("cls");
                    Zamowienie* z = M1->wybierz_zamowienie("Zlozone");
                    if (z != nullptr) {
                        M1->przygotuj_zamowienie(z);
                    }
                    cout << endl << endl;
                    break;
                }
                case 4:
                {
                    system("cls");
                    Towar* t = M1->wybierz_towar("");
                    int oIle;
                    cout << "\n Zmien stan magazynowy towaru \n";
                    t->wyswietl_dane_towaru();
                    cout << "Podaj ilosc: \n";
                    cin >> oIle;
                    t->zmien_ilosc_w_magazynie(oIle);
                    cout << endl << endl;
                    break;
                }
                case 5:
                {
                    system("cls");
                    M1->dodaj_towar();
                    break;
                }
                case 6:
                {
                    system("cls");
                    cout << "\n Usuwanie towaru \n";
                    Towar* t = M1->wybierz_towar("");
                    t->set_status("Usuniety");
                    t->wyswietl_dane_towaru();
                    cout << endl << endl;
                    break;
                }
                default:
                    system("cls");
                    break;
                }

            }
            break;
        case 0:
            program = false;
        default:
            system("cls");
        }
    }
    for (Towar* t : towary) {
        delete t;  
    }
    towary.clear();
    return 0;
}
