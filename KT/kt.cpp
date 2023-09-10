#include "asfalt.h"
#include "lauljad.h"
#include <iostream>

int main() {
    //std::cout << ajakulu(57.4f) << "\n";
    //std::cout << teepikus(7.12f, 1800) << "\n";
    //std::cout << arvuta_ajakulu(7.12f, 1800) << "\n";

    float laius;
    float liiter;

    std::cout << "Tee laius: ";
    std::cin >> laius;
    std::cout << "Asfalti kogus: ";
    std::cin >> liiter;
    std::cout << "Kuluv aeg: " << arvuta_ajakulu(laius, liiter) << "\n";

    std::cout << "\n-----------------------\n\n";

    lauljad<int>(1, "lauljad.txt");


    return 0;
}