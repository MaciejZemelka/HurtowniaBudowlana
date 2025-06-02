#ifndef POZYCJEZAMOWIEN_H
#define POZYCJEZAMOWIEN_H

#include "PozycjeZamowien.h"
#include "Towar.h"
#include <string>
#include <vector>

using namespace std;
class PozycjeZamowien
{
private:
	Towar* towar;
	int ilosc;
public:

	PozycjeZamowien(Towar* towar, int ilosc);
	void wyswietl_pozycje();
	void zmien_ilosc();
	void oblicz_wartosc_pozycji();
	Towar* get_towar();
	int get_ilosc();
};


#endif