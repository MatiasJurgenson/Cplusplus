#include "prax4.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>

void sagedus(const std::string &asukoht) {
    std::ifstream sisend(asukoht);
    if (!sisend.is_open()) {
        std::cerr << "Faili '" << asukoht << "' ei saanud avada.\n";
        return;
    }
    std::string rida;
    while (getline(sisend, rida)) {
        // javas HashMap<string, int>
        std::map<std::string, int> m;

        std::stringstream ss(rida);
        std::string sõna;

        while (ss >> sõna) {
            auto it = m.find(sõna);
            if (it == m.end()) {
                m.insert({sõna, 1});
            } else {
                it->second++;
            }

        }
        
        std::string maxStr;
        int maxVal{INT_MIN};

        for (auto &[key, value] : m) {
            if (value > maxVal) {
                maxVal = value;
                maxStr = key;
            } 
        }

    }

}



int main() {
    sagedus("sisend.txt");
    sagedus("ei_eksisteeri.txt");

    std::cout << liidaJaPiira(4, 1) << '\n';
    std::cout << liidaJaPiira(10, 100) << '\n';
    std::cout << liidaJaPiira<int, 0>(0, 1) << '\n';
    
    auto asukoht = std::filesystem::path("elemendid.txt");
    std::string elemendid[] = {"üks", "kaks", "kolm"};
    looFailJaKirjuta<std::string>(asukoht, elemendid, 3);

    return 0;
}