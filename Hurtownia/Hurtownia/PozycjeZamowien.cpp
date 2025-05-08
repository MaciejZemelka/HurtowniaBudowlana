#include "PozycjeZamowien.h"
#include <iostream>

using namespace std;


PozycjeZamowien::PozycjeZamowien(Towar* towar, int ilosc) :
								 towar(towar), ilosc(ilosc){};

void PozycjeZamowien::wyswietl_pozycje() {
	towar->wyswietl_dane_towaru();
	cout << ' | ' << ilosc << ' | ' << ilosc*towar->get_cena();
};