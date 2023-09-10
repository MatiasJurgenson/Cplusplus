#include "algarv.h"

#include "minutaisarv.h"
#include <cmath>

#include <iostream>

// Selle funktsiooni implementatsiooni võib julgelt muuta
// NB! Ära signatuuri muuda!
bool onAlgarv(int n) {
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

Algarv::Algarv(int ntäisarv) : MinuTaisarv(ntäisarv) {
    if (onAlgarv(ntäisarv) == 0) {
        mitmes = -1;
    } else {
        for (int i = 1; i <= ntäisarv; i++) {
            if (onAlgarv(i)) {
                mitmes++;
            }
        }
    }
}

Algarv Algarv::operator++(int i){
    Algarv vana = *this;
    MinuTaisarv::täisarv++;
    while (onAlgarv(MinuTaisarv::täisarv) == 0) {
        MinuTaisarv::täisarv++;
    }
    mitmes++;

    return vana;
}

Algarv Algarv::operator--(int i){
    Algarv vana = *this;
    MinuTaisarv::täisarv--;
    while (onAlgarv(MinuTaisarv::täisarv) == 0) {
        MinuTaisarv::täisarv--;
    }
    mitmes--;

    return vana;
}

ostream& operator<<(ostream& os, const Algarv& a){
    os << "Arv " << a.täisarv << " on " << a.mitmes << ". algarv";
    return os;
}

int loeArv(int i) {
    int summa = 0;

    if (onAlgarv(i)) {
        Algarv arv(i);

        int j = 0;
        
        while (arv[j] != -1) {
            summa += arv[j];
            j++;
        }


    } else {
        MinuTaisarv arv(i);

        int j = 0;
        
        while (arv[j] != -1) {
            summa += arv[j];
            j++;
        }
    }

    return summa;
}