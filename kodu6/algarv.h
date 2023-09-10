#ifndef KODU6_ALGARV_H
#define KODU6_ALGARV_H

#include "minutaisarv.h"

bool onAlgarv(int);

class Algarv : public MinuTaisarv{

private:
    int mitmes{};

public:
    Algarv(int ntäisarv); 

    Algarv operator++(int);
    Algarv operator--(int);

    friend ostream& operator<<(ostream& os, const Algarv& a);
};

int loeArv(int);

#endif