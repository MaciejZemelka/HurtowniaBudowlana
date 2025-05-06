#include "Magazyn.h"
#include <iostream>
#include <vector>

using namespace std;

Magazyn::Magazyn(vector<Towar*> towary) : towary(towary) {};
void Magazyn::wyswietl_dostepne_towary() {
	cout << endl << endl;
	cout << "============================";
	cout << "Lista dostêpnych towarow:";
	cout << "============================\n";
	cout << " Nazwa towaru | Cena | Status | ilosc w magazynie \n";
	for (Towar* wsk : towary) {
		if (wsk->get_status() == "Dostepny") {
			wsk->wyswietl_dane_towaru();
			cout << endl;
		}
	}
};


void Magazyn::wyswietl_wszystkie_towary() {
	cout << endl << endl;
	cout << "============================";
	cout << "Lista wszystkich towarow:";
	cout << "============================\n";
	cout << " Nazwa towaru | Cena | Status | ilosc w magazynie \n";
	for (Towar* wsk : towary) {
		wsk->wyswietl_dane_towaru();
		cout << endl;
	}
};