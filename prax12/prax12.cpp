#include "stuff.h"

#include <fstream>
#include <iostream>

int main() {
    std::vector<Tudeng> tudengid;

    std::fstream fail("andmed.txt");

    if (!fail.is_open()) {
        std::cerr << "Faili 'andmed.txt' ei saanud avada.\n";
    } else {
        std::string rida;

        while (getline(fail, rida)) {
            tudengid.push_back(lisa_üliõpilane(rida));
        }
    }

    return 0;
}