#ifndef TOWAR_H
#define TOWAR_H

#include "Towar.h"
#include <string>
#include <vector>

using namespace std;
class Towar
{
private:
	string nazwa;
	float cena;
	string status;
	int iloscZarezerwowana;
	int iloscWMagazynie;
public:
	Towar(string nazwa, float cena, string status, int iloscZarezerwowana, int iloscWMagazynie);
	void wyswietl_dane_towaru();
	string get_status();
	float get_cena();
	void zmien_ilosc_zarezerwowanych(int ile);
	void zmien_ilosc_w_magazynie(int ile);
};


#endif