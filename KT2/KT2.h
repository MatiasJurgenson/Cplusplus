#ifndef KT2_H
#define KT2_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <map>


//ÜL 1

template <typename T, bool kasKasvavalt>
class MinuMassiiv {
public:
    std::vector<T> m_elemendid{};

    MinuMassiiv(std::vector<T> elemendid) : m_elemendid(elemendid) {} 

    void sorteeria() {
        std::sort(m_elemendid.begin(), m_elemendid.end());
        if (!kasKasvavalt) {
            std::reverse(m_elemendid.begin(), m_elemendid.end());
        }
    }

    void lisaElement(T element) {
        m_elemendid.push_back(element);
    }

    void lisaElemendid(MinuMassiiv massiiv) {
        std::for_each(massiiv.m_elemendid.begin(), massiiv.m_elemendid.end(), [this](T &n){m_elemendid.push_back(n);});
    }

    bool kasMassiivis(T element) {
        return std::find(m_elemendid.begin(), m_elemendid.end(), element) != m_elemendid.end();
    }

    T& operator[] (const int i) {
        return m_elemendid[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const MinuMassiiv& m){
        for (int i = 0; i < (int)m.m_elemendid.size(); i++) {
            os << m.m_elemendid[i] << " ";
        }
        return os;
    }


};




//ül 3

void buss(std::string failinimi) {
     std::fstream fail(failinimi);

    if (!fail.is_open()) {
        std::cerr << "Faili '" << failinimi << "' ei saanud avada.\n";
        return;
    }

    std::cout << "Bussis on vabad järgmised kohad:\n";

    std::string rida, asukohad = "";
    int mitu_märki = 0, rea_arv = 0;

    while (getline(fail, rida)) {
        //.split() 

        rea_arv++;

        std::size_t split = rida.find(" ");

        while (split != std::string::npos) {
            
            std::string märk = rida.substr(0, split);
            
            if(märk == "V" or märk == "R") {
                mitu_märki++;
                if(märk == "V") {
                    asukohad += std::to_string(mitu_märki) + " ";
                }
            }

            rida = rida.substr(split + 1, rida.length());
            split = rida.find(" ");
        }
        std::string märk = rida.substr(0, split);
        
        if(märk == "V" or märk == "R") {
                mitu_märki++;
                if(märk == "V") {
                    asukohad += std::to_string(mitu_märki) + " ";
                }
            }

        if ((int)asukohad.size() != 0) {
            
            rida = rida.substr(split + 1, rida.length());
            split = rida.find(" ");
            
            std::cout << "rida " << rea_arv;
            for (int i = 0; i < (int)asukohad.size(); i ++) {
                
                std::size_t split = asukohad.find(" ");
                while (split != std::string::npos) {
                    std::string koht = asukohad.substr(0, split);
                    std::cout << " koht " << std::stoi(koht);
                    asukohad = asukohad.substr(split + 1, asukohad.length());
                    split = asukohad.find(" ");
                }
            }
            std::cout << "\n";
            mitu_märki = 0;
            asukohad = "";
        }
    }
}
 
#endif