#ifndef MAGAZYN_H
#define MAGAZYN_H

#include "Magazyn.h"
#include "Towar.h"
#include <string>
#include <vector>

using namespace std;
class Magazyn
{
private:
	vector<Towar*> towary;
public:
	Magazyn(vector<Towar*> towary);

	void wyswietl_dostepne_towary();
	void wyswietl_wszystkie_towary();

};


#endif