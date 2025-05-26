#ifndef MAGAZYN_H
#define MAGAZYN_H

#include "Magazyn.h"
#include "Towar.h"
#include "Zamowienie.h"
#include "Firma.h"
#include <string>
#include <vector>

using namespace std;
class Magazyn
{
private:
	Firma* firma;
	vector<Towar*> towary;
public:
	Magazyn(Firma* f);

	void wyswietl_towary(string status);
	void usun_towar();
	void dodaj_towar();
	void zloz_zamowienie(Klient k);
	void wyswietl_zamowienia(string status);
	Towar* wybierz_towar();
	bool czy_towar_dostepny(Towar t, int ilosc);
	Zamowienie* wybierz_zamowienie();
};


#endif