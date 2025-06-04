#include "DostawcaTowaru.h"
#include <iostream>
using namespace std;

DostawcaTowaru::DostawcaTowaru() {}

void DostawcaTowaru::wyswietl_towary_dostawcy() {
    if (towaryDostawcy.empty()) {
        cout << "Brak towar�w u dostawcy." << endl;
        return;
    }

    cout << "Towary dost�pne u dostawcy:" << endl;
    for (auto& towar : towaryDostawcy) {
        towar.wyswietl_dane_towaru();
    }
}