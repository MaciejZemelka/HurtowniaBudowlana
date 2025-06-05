#include "Czlowiek.h"
#include <iostream>
using namespace std;

string Czlowiek::get_imie()
{
    return this->imie;
}

void Czlowiek::wypisz_dane()
{
    cout << "Dane klienta" << this->get_imie();
}

Czlowiek::Czlowiek(std::string imie, std::string nazwisko)
    : imie(imie), nazwisko(nazwisko) {}

