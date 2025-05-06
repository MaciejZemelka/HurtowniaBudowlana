#include "Towar.h"
#include <iostream>

using namespace std;

Towar::Towar(string nazwa, float cena, string status, int iloscZarezerwowana, int iloscWMagazynie) :
	nazwa(nazwa), cena(cena), status(status), iloscZarezerwowana(iloscZarezerwowana), iloscWMagazynie(iloscWMagazynie) {};

void Towar::wyswietl_dane_towaru() {
	cout << this->nazwa << " | " << this->cena << "zl | " << this->status << " | " << this->iloscWMagazynie;
};

string Towar::get_status() {
	return this->status;
}

float Towar::get_cena() {
	return this->cena;
}

void Towar::zmien_ilosc_zarezerwowanych(int ile) {
	iloscZarezerwowana += ile;
};

void Towar::zmien_ilosc_w_magazynie(int ile) {
	iloscWMagazynie += ile;
};