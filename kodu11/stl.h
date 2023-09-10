#ifndef STL_H
#define STL_H

#include <iostream>
#include <iterator>

/*
pop_back() //eemaldab viimse elemendi
push_back() //lisab uue elemndi lõppu
size() // suurus
back() //viimane element
*/

template <typename T1, typename T2, typename T3>
void yhenda(T1& alg1, T2& alg2, T3& tulem) {
    auto alg1_algus = alg1.begin();
    auto alg1_lõpp = alg1.end();

    while (alg1_algus != alg1_lõpp) {
        tulem.push_back(*alg1_algus);
        alg1_algus++; // nihutamine ühe elemendi võrra
    }
    
    auto alg2_algus = alg2.begin();
    auto alg2_lõpp = alg2.end();

    while (alg2_algus != alg2_lõpp) {
        tulem.push_back(*alg2_algus);
        alg2_algus++; // nihutamine ühe elemendi võrra
    }
}

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

template <typename T>
bool operator<(T& esimene, T& teine) {
    
    auto esimene_algus = esimene.begin();
    auto esimene_lõpp = esimene.end();
    auto esimene_summa = 0;

    while (esimene_algus != esimene_lõpp) {
        esimene_summa += *esimene_algus;
        esimene_algus++; // nihutamine ühe elemendi võrra
    }

    auto teine_algus = teine.begin();
    auto teine_lõpp = teine.end();
    auto teine_summa = 0;

    while (teine_algus != teine_lõpp) {
        teine_summa += *teine_algus;
        teine_algus++; // nihutamine ühe elemendi võrra
    }

    return esimene_summa < teine_summa;

}

#endif