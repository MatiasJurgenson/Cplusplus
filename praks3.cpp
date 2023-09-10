#include "funktsioon.h"
#include <iostream>
#include <sstream>


std::string lyhendaja_rec(std::string nimi) {
    auto esimene_tyhik = nimi.find(" ");
    //kui leidub tühik pole perenimi
    if (esimene_tyhik == std::string::npos) {
        return nimi;
    }

    std::string eesnimi = nimi.substr(0, esimene_tyhik);
    nimi = nimi.substr(esimene_tyhik + 1, nimi.length());
    
    std::string e{eesnimi.at(0)};

    return lyhendaja_rec(nimi) + (" " + e + ". ");

}

std::string lyhendaja(std::string nimi) {
    std::stringstream ss(nimi);
    std::string osa;
    std::string tulemus;
    while (ss >> osa) {
        bool isPerenimi = ss.eof();
        if (isPerenimi) {
            tulemus = osa + " " + tulemus;
        } else {
            tulemus += osa.at(0);
            tulemus +=". ";
        }

    }

    return tulemus;
}

std::reverse; //teeb massiivi tagurpidi

int main() {
    std::cout << lyhendaja("Otto Triin Kaido Maastik");
}