#include "PahupidiArv.h"
#include <iostream>

PahupidiArv::PahupidiArv(int arv)
        :m_Arv(arv) {
            std::cout << "Konstruktor\n";
        }

PahupidiArv::PahupidiArv(const PahupidiArv &o) {
    m_Arv = o.m_Arv;
}

PahupidiArv &PahupidiArv::operator=(const PahupidiArv &o) {
    return *this;
}

int PahupidiArv::operator+(int arv) {
    return m_Arv - arv;
}

int PahupidiArv::arv() {
    return m_Arv;
}

void PahupidiArv::arv(int arv) {
    m_Arv = arv;
}