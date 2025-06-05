#include "PozycjeZamowien.h"
#include <iostream>

using namespace std;


PozycjeZamowien::PozycjeZamowien(Towar* towar, int ilosc) :
								 towar(towar), ilosc(ilosc){};

void PozycjeZamowien::wyswietl_pozycje() {
	towar->wyswietl_dane_towaru();
	cout << " | " << ilosc << " | " << ilosc * towar->get_cena() << " z³" << endl;
}

void PozycjeZamowien::zmien_ilosc() {
	cout << "Podaj now¹ iloœæ: ";
	cin >> ilosc;
}

void PozycjeZamowien::oblicz_wartosc_pozycji()
{
	cout << "Wartosc pozycji: " << ilosc * towar->get_cena() << " z³" << endl;
}

Towar* PozycjeZamowien::get_towar()
{
	return towar;
}

int PozycjeZamowien::get_ilosc()
{
	return ilosc;
}
