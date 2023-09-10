#include "loomad.h"
#include <iostream>

Loomad::Loomad(std::string m_nimi) : nimi {m_nimi} {}

void Loomad::häälitsus() {
    std::cout << "hääiltsus" << "\n";
}

ostream& operator<<(ostream& os, const Loomad& l) {
    os << "Looma nimi on " << l.nimi;
    return os;
}

Roomajad::Roomajad(std::string m_nimi, int m_jalgadeArv) : Loomad(m_nimi), jalgadeArv{m_jalgadeArv} {}

Madu::Madu(std::string m_nimi, int m_jalgadeArv) : Roomajad(m_nimi, m_jalgadeArv) {}

//ülemklassi häälitsus() ülekatmine
void Madu::häälitsus() {
    std::cout << "sss-sss" << "\n";
}