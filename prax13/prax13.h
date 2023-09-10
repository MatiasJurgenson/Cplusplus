#ifndef PRAX13_H
#define PRAX13_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

void viska(auto x) {
    if (x == 1) {
        throw int(x);
    }
    if (x == 2) {
        throw std::string("paar");
    }
}

class ArvuPole : public std::exception {
public:
    auto what() {
        return "Arvu pole";
    }
};

class PoleArv : public std::exception {
public:
    auto what() {
        return "Pole arvuks teisendatav";
    }
};

class ArvuLugeja {
public:
    static std::vector<int> arvud(std::string sisend) {
        std::vector<int> vektor;

        std::stringstream ss;
        for (const auto ch : sisend) {
            //std::cout << ch << "\n";
            //std::cout << ss.str() << "\n";

            if (ch == ',') {
                if (ss.str().empty()) {
                    throw ArvuPole();
                }

                try {
                    auto i = std::stoi(ss.str());

                    vektor.push_back(i);
                    
                    ss.str("");
                    continue;
                } catch (std::exception& e) {
                    throw PoleArv();
                }
            }

            ss << ch;
        }

        return vektor;
    }
};

class Pitsa {
private:
    std::string m_nimi;
    float m_hind;

private:
    Pitsa(std::string nimi, float hind) : m_nimi(nimi), m_hind(hind) {}

};

class Tellimus {
private:
    std::string m_tellija;
    std::vector<Pitsa> m_pitsad;
    int m_ooteaeg;

public:
    Tellimus(std::string tellija, std::vector<Pitsa> pitsad, int ooteaeg) : m_tellija(tellija), m_pitsad(pitsad), m_ooteaeg(ooteaeg) {}
};

class LiigaPikkOotamineErind : std::exception {

};

class Peaklass {

};

#endif