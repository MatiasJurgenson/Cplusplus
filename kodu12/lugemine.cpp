#include "lugemine.h"
#include <fstream>
#include <filesystem>
#include <iostream>

Hoia::

std::string Hoia::getVäärtus() {
    return m_väärtus;
}

bool operator<(Hoia h1, Hoia h2) {
    //return h1.getVäärtus().compare(h2.getVäärtus());
    return h1.getVäärtus() < h2.getVäärtus();
}


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

