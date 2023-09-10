#include "prax13.h"

#include <iostream>

int main() {

    std::vector<int> vektor{0, 1, 2, 3};

    for (auto el : vektor) {
        try {
            viska(el);
            std::cout << "korras\n";
        } catch(int e) {
            std::cout << "int " << el << "\n";
        } catch(std::string e) {
            std::cout << "string " << el << "\n";
        } catch(...) { //püüab kõik kinni aga vaja lisa asju teha
            std::cout << "UwU\n";
        }
    }

    ArvuLugeja::arvud("a,b,c,d");

    return 0;
}