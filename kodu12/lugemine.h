#ifndef LUGEMINE_H
#define LUGEMINE_H

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

class Hoia {
private:
    std::string m_väärtus{};

public:
    Hoia(std::string väärtus) : m_väärtus(väärtus) {}
    std::string getVäärtus() {
    return m_väärtus;
    }

    friend bool operator<(Hoia h1, Hoia h2) {
    //return h1.getVäärtus().compare(h2.getVäärtus());
    return h1.getVäärtus() < h2.getVäärtus();
    }

    friend std::ostream& operator<<(std::ostream& os, Hoia& h) {
    os << h.getVäärtus();
    return os;
    }
};

std::set<Hoia>& loe_hoia(std::string failinimi, std::set<Hoia>& st) {
    std::fstream fail(failinimi);

    if (!fail.is_open()) {
        std::cerr << "Faili '" << failinimi << "' ei saanud avada.\n";
        return st;
    }

    std::string rida;

    while (getline(fail, rida)) {
        //.split() 
        std::size_t split = rida.find(" ");

        while (split != std::string::npos) {
            
            //std::cout << rida.substr(0, split) << "\n";
            Hoia hoia{rida.substr(0, split)};

            st.insert(hoia);
            
            rida = rida.substr(split + 1, rida.length());
            //std::cout << rida << "\n";
            split = rida.find(" ");
        }
    }

    return st;

}

template<typename T1, typename T2>
std::map<T1, T2>& loe_failist(std::string failinimi, std::map<T1, T2>& m ){
    std::fstream fail(failinimi);

    if (!fail.is_open()) {
        std::cerr << "Faili '" << failinimi << "' ei saanud avada.\n";
        return m;
    }

    std::string rida;
    std::string sõna;

    while (getline(fail, rida)) {
        //.split() 
        std::size_t split = rida.find(" ");

        while (split != std::string::npos) {
            sõna = rida.substr(0, split);

            if (sõna.ends_with(",") || sõna.ends_with(".") || sõna.ends_with(";") || sõna.ends_with(":") || sõna.ends_with("!") || sõna.ends_with("?")) {
                sõna = sõna.substr(0, sõna.length() - 1);
            }
            
            std::transform(sõna.begin(), sõna.end(), sõna.begin(),[](unsigned char c){ return std::tolower(c); }); 
            ++m[sõna];

            rida = rida.substr(split + 1, rida.length());
            //std::cout << rida << "\n";
            split = rida.find(" ");
        }

        sõna = rida.substr(0, split);

        if (sõna.ends_with(",") || sõna.ends_with(".") || sõna.ends_with(";") || sõna.ends_with(":") || sõna.ends_with("!") || sõna.ends_with("?")) {
                sõna = sõna.substr(0, sõna.length() - 1);
            }
            
        std::transform(sõna.begin(), sõna.end(), sõna.begin(),[](unsigned char c){ return std::tolower(c); });
        ++m[sõna];

    }

    return m;
}


#endif