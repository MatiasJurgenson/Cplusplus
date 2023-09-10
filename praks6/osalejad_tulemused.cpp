#include "osalejad_tulemused.h"
#include <string>
#include <iostream>

Tulemus::Tulemus(std::string ik, std::string nimi, int koht) : m_isikukood(ik), m_voistluseNimi(nimi), m_koht(koht) {}

auto Tulemus::getIsikukood() {
    return m_isikukood;
}

auto Tulemus::getVoistluseNimi() {
    return m_voistluseNimi;
}

auto Tulemus::getKoht() {
    return m_koht;
}

std::ostream& operator<<(std::ostream& os, const Tulemus& t){
    os << "MinuTaisarv: ";
    return os;
}

void loe_failist(std::string path, std::vector<Tulemus> &Tulemus);