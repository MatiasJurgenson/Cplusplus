#include "algarv.h"
#include "minutaisarv.h"
#include "toit.h"

#include <iostream>

#if defined(VPL_TEST_ARV)

    // 1. ülesande funktsioonid panna siia ploki sisse
    
#endif

#if defined(VPL_TEST_TOIT)

    // 2. ülesande funktsioonid panna siia ploki sisse
    
#endif

#if !defined(VPL_TEST)
int main() {
    // Testi siin oma klasse ja funktsioone
    
    MinuTaisarv arv2 = 103;
    std::cout << arv2 << "\n";
    std::cout << arv2[2] << "\n";

    MinuTaisarv arv;
    std::cout << arv << "\n";
    std::cout << arv[0] << "\n";
    std::cout << "-------------------------\n";


    Algarv arv3(6);
    Algarv uusArv = arv3++;
    Algarv uusArv2 = uusArv--;
    std::cout << arv3 << '\n';
    std::cout << uusArv << '\n';
    std::cout << uusArv2 << '\n';
    std::cout << "-------------------------\n";

    int i = loeArv(123);
    std::cout << i << '\n';
    int j = loeArv(1);
    std::cout << j << '\n';
    std::cout << "-------------------------\n";

    std::vector<Toit> viide;
    float kokku = loe_toidud("toit.txt", &viide);
    std::cout << kokku << "\n";
    
    for (auto toit : viide) {
        std::cout << toit << "\n";
    }

}
#endif