#include "raamat.h"

#include <iostream>
#include <cmath>

Teos::Teos(std::string nimi, std::string tahis, std::shared_ptr<std::string> laenutajaNimi, int paevadearv) : m_nimi(nimi) {}

int Teos::laenutusaeg() {
    if (m_tahis == "roheline") {
        return 1;
    }
    if (m_tahis == "puudub") {
        return 14;
    }
    if (m_tahis == "kollane") {
        return 30;
    }
    if (m_tahis == "sinine") {
        return 60;
    }
    return 0;
}

float Teos::paevaneViivis() {
    auto laenutusAeg = laenutusaeg();
    switch (laenutusAeg) {
        case 30:
        case 60:
            return 0.05f;
        case 14:
            return 0.15f;
        case 1:
            return 2.0f; 
        default:
            return 0.0f;      
    }
}

void Teos::arvutaViivis(std::shared_ptr<Kontrollija> Kontrollija) {
    auto viivisePäevad = m_paevadeArv - paevaneViivis();
    auto viivis = std::max(0.0f, viivisePäevad);
    Kontrollija->salvestaViivis(m_laenutajanimi, m_nimi, viivis);
}

std::ostream &Teos::print(std::ostream &o) {
    return o;
}



ViiviseHoidja::ViiviseHoidja(float viivis) : m_viivis(viivis), m_nimed(new std::vector<std::shared_ptr<std::string>>) {}

ViiviseHoidja::~ViiviseHoidja() {
    delete m_nimed;
}

void ViiviseHoidja::salvestaViivis(std::shared_ptr<std::string> laenutajaNimi, std::string teoseNimi, float viivis) {
    if (viivis < m_viivis) {
        return;
    }

    bool exists = false;

    for (auto &nimi : *m_nimed) {
        if (*nimi == *laenutajaNimi) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        m_nimed->push_back(laenutajaNimi);
    }
}

void SuurimaViiviseLeidja::salvestaViivis(std::shared_ptr<std::string> laenutajaNimi, std::string teoseNimi, float viivis) {
    if (viivis < m_viivis) {
        m_laenutajaNimi = laenutajaNimi;
        m_teoseNimi = teoseNimi;
        m_viivis = viivis;
    }
}

void SuurimaViiviseLeidja::saadaHoiatus() {
    std::cout << "Suurima viivisega on " << *m_laenutajaNimi << " teosega " << m_teoseNimi << "\n";
}