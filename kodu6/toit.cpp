#include "toit.h"

#include <iostream>
#include <fstream>

Toit::Toit(std::string m_toiduNimetus, float m_hind) : toiduNimetus {m_toiduNimetus}, hind {m_hind} {}

std::string Toit::getToiduNimetus() {
    return toiduNimetus;
}

void Toit::setToiduNimetus(std::string nimi) {
    toiduNimetus = nimi;
}

float Toit::getHind() {
    return hind;
}
void Toit::setHind(float uus){
    hind = uus;
}

bool operator<=(const Toit& l, const Toit& r) {
    return l.hind <= r.hind;
}

ostream& operator<<(ostream& os, const Toit& t) {
    os << "Toidu nimi: " << t.toiduNimetus << ", toidu hind; " << t.hind;
    return os;
}



KampaaniaToit::KampaaniaToit(std::string m_toiduNimetus, float m_hind, int m_soodustuseProtsent) : Toit(m_toiduNimetus, m_hind), 
    soodustuseProtsent {m_soodustuseProtsent} {}

float KampaaniaToit::getHind() {
    return hind*(float)(100-soodustuseProtsent)/100;
}

bool operator<=(const KampaaniaToit& l, const KampaaniaToit& r) {
    float lHind = l.hind*(float)(100-l.soodustuseProtsent)/100;
    float rHind = r.hind*(float)(100-r.soodustuseProtsent)/100;
    return  lHind <= rHind;
}
ostream& operator<<(ostream& os, const KampaaniaToit& t){
    float soodustus = t.hind*(float)(100-t.soodustuseProtsent)/100;
    os << "Toidu nimi: " << t.toiduNimetus << ", toidu hind, " << t.hind << ", soodustus: " << t.soodustuseProtsent << ", toidu hind soodustusega: " << soodustus;
    return os;
}

float loe_toidud(std::string failiNimi, std::vector<Toit> *viide) {
    std::fstream fail(failiNimi);
    std::string rida;

    float summa = 0;

    while (getline(fail, rida)) {
        //.split() 
        std::size_t split = rida.find(",");

        std::string nimi = rida.substr(0, split);

        rida = rida.substr(split + 1, rida.length());
        split = rida.find(",");

        float hind = std::stof(rida.substr(0, split));

        rida = rida.substr(split + 1, rida.length());
        split = rida.find(",");
        /*
        std::cout << "mitu: ','-ni " << split << "\n";
        std::cout << "rida: " << rida << "\n";
        std::cout << "int: " << rida.substr(0, split) << "\n";
        */

        if (rida.length() != 0) {
            int soodustus = std::stoi(rida.substr(0, split));
            
            KampaaniaToit kampaaniaToit(nimi, hind, soodustus);

            summa += kampaaniaToit.getHind();
            viide->push_back(kampaaniaToit);

        } else {
            Toit toit(nimi, hind);

            summa += toit.getHind();
            viide->push_back(toit);
        }
    }

    /*
    for (auto jah : *viide) {
        std::cout << "hind: " << jah.getHind() <<"\n";
        summa += jah.getHind();
    }
    */
    return summa;
}

