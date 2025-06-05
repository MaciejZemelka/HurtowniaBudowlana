#include "Firma.h"
#include <iostream>
using namespace std;

Firma::Firma(string& nazwa, string& adres, string& nip): nazwa(nazwa), adres(adres), nip(nip) {}

void Firma::wyswietl_dane_firmy() {
    std::cout << "Nazwa firmy: " << nazwa << std::endl;
    std::cout << "Adres: " << adres << std::endl;
    std::cout << "NIP: " << nip << std::endl;
}

std::string Firma::get_nazwa() {
    return nazwa;
}

std::string Firma::get_adres() {
    return adres;
}

std::string Firma::get_nip() {
    return nip;
}
