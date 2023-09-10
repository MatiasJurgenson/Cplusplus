#ifndef PRAX10_H
#define PRAX10_H

#include <iostream>

template <typename T>
std::ostream& tryki(T& alg, std::ostream & os) {
    auto alg_algus = alg.begin();
    auto alg_lõpp = alg.end();

    while (alg_algus != alg_lõpp) {
        os << *alg_algus << " ";
        alg_algus++; // nihutamine ühe elemendi võrra
    }
    os << '\n';

    return os;
}

//ÜL1

template<typename Conteiner, typename T>
bool leidub(Conteiner &c, T &el) {
    for (auto &e : c) {
        if (e == el) {
            return true;
        }
    }
    return false;

}

template <typename T1, typename T2, typename T3>
void yhisosa(T1& esimene, T2& teine, T3& kolmas){
    for (auto &el : esimene) {
        bool exists = leidub(teine, el);
        if (exists) {
            exists = leidub(kolmas, el);
            if (!exists) {
                kolmas.push_back(el);
            }
        }
    }
        
}

template <typename T1, typename T2, typename T3>
void yhend(T1& esimene, T2& teine, T3& kolmas) {
    for (auto &el : esimene) {        
        bool exists = leidub(kolmas, el);
        if (!exists) {
            kolmas.push_back(el);
        }
    }

    for (auto &el : teine) {        
        bool exists = leidub(kolmas, el);
        if (!exists) {
            kolmas.push_back(el);
        }
    }
}

template <typename T1, typename T2, typename T3>
void vahe(T1& esimene, T2& teine, T3& kolmas) {
    for (auto &el : esimene) {
        bool exists = leidub(teine, el);
        if (!exists) {
            exists = leidub(kolmas, el);
            if (!exists) {
                kolmas.push_back(el);
            }
        }
    }
}

//ÜL2

template <typename T>
void täida(T& andmed, int n) {
    for (int i = 0; i < n; i++) {
        andmed.push_back(i);
    }
}

template <typename T>
int summa1(T& andmed) {
    int summa = 0;
    for (int i = 0; i < (int)andmed.size(); i++) {
        summa += andmed[i];
    }
    return summa;
}

template <typename T>
int summa2(T& andmed) {
    int summa = 0;
    auto andmed_algus = andmed.begin();
    auto andmed_lõpp = andmed.end();
    while (andmed_algus != andmed_lõpp) {
        summa += *andmed_algus;
        andmed_algus++; // nihutamine ühe elemendi võrra
    }
    return summa;
}

#endif