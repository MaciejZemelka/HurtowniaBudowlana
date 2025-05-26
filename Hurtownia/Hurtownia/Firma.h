#ifndef FIRMA_H
#define FIRMA_H

#include <string>

using namespace std;
class Firma {
private:
	string nazwa;
	string adres;
	string nip;
public:
	Firma(string& nazwa, string& adres, string& nip);

	void wyswietl_dane_firmy();

};

#endif
