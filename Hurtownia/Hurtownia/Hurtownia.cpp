#include <iostream>
#include "Klient.h"
#include "Towar.h"
#include "Magazyn.h"
#include <windows.h> 

int main() {
    

    Towar* T1 = new Towar("Łopata", 50.99, "Dostepny", 0, 100);
    Towar* T2 = new Towar("Młot", 29.99, "Dostepny", 0, 100);
    Towar* T3 = new Towar("Cement 10kg", 10.99, "Dostepny", 0, 100);
    Towar* T4 = new Towar("Cegły 100szt", 250, "NieDostepny", 0, 0);
    vector<Towar*> towary;
    towary.push_back(T1); 
    towary.push_back(T2);
    towary.push_back(T3);
    towary.push_back(T4);

    Magazyn M1 = Magazyn(towary);

   // M1.wyswietl_wszystkie_towary();
   

    Klient klient("Jan", "Nowak");
    int osoba;
    int akcja = -1;
    cout << "============================";
    cout << "Witaj w hurtowni materiałów budowlanych";
    cout << "============================\n\n";
    while (true) {
        cout << "Kim dzisiaj jesteś?:\n";
        cout << "1. klient\n";
        cout << "2. pracownik\n";
        cout << "3. kierownik\n";
        cout << "0. wyjście z programu\n";
        cout << "Wybrana akcja: ";
        cin >> osoba;

        switch (osoba) {
        case 1:
            while (akcja != 0) {
                cout << "Wybierz akcje:\n";
                cout << "1. Wyświetl listę dostępnych towarów\n";
                cout << "2. Zamów produkt\n";
                cout << "3. Sprawdź stan zamówienia\n";
                cout << "4. Odbierz zamówienie\n";
                cout << "5. Zwrot zamówienia\n";
                cout << "0. wyjście do wyboru\n";
                cout << "Wybrana akcja: ";
                cin >> akcja;
                switch (akcja) {
                case 1:
                    M1.wyswietl_dostepne_towary();
                    break;
                default:
                    break;
                }

            }
            break;
        case 2:
            // code block
            break;
        case 3:
            // code block
            break;
        case 0:
            return -1;
        default:
            "Wybrano nieprawidlowo";
        }
    }
    for (Towar* t : towary) {
        delete t;  
    }
    towary.clear();
    return 0;
}
