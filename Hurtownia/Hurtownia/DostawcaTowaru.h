#ifndef DOSTAWCATOWARU_H
#define DOSTAWCATOWARU_H

#include <vector>
#include "Towar.h"

class DostawcaTowaru {
private:
    vector<Towar> towaryDostawcy;

public:
    DostawcaTowaru();
    void wyswietl_towary_dostawcy();
};

#endif
