#ifndef LAULJAD_H
#define LAULJAD_H

#include <string>
#include <fstream>
#include <filesystem>
#include <concepts>
#include <iostream>



template<typename T>
requires std::integral<T>
void lauljad(T arv, std::string failiNimi) {

    std::fstream fail(failiNimi);

    if (!fail.is_open()) {
        std::cerr << "Faili '" << failiNimi << "' ei saanud avada.\n";
        return;
    }

    std::string rida;
    int index = 0;
    int eesnimedeSumma = 0;
    int nimedeSumma = 0;
    std::string eesnimed = "Eesnimed: ";

    while (getline(fail, rida)) {
        //vaatab mitu rida saab väljastada
        if (index++ < arv) {
            std::cout << rida << "\n";
            nimedeSumma += (int)rida.length();

            std::size_t split = rida.find(" ");
            std::string eesnimi = rida.substr(0, split);
            eesnimedeSumma += (int)eesnimi.length();
            eesnimed += eesnimi + " ";
        }
    }

    std::cout << eesnimed << "\n";
    std::cout << "Eesnimede kogupikkus: " << eesnimedeSumma << "\n";
    std::cout << "Nimede kogupikkus: " << nimedeSumma << "\n";
    std::cout << "Eesnimed moodustavad nimedest " << (double)(eesnimedeSumma * 100.0) / nimedeSumma  << " protsenti.";

}

#endif