#include "kujund.h"

#include <iostream>


int main(){
    
    std::vector<float> arvud1{1, 1};
    std::vector<float> arvud2{2, 2};
    
    const int arv = 5;
    Punkt<arv> punkt0;
    std::cout << "P0: " << punkt0.toString() << '\n';
    std::cout << punkt0.getKoordinaadid() << '\n';
    
    Punkt<2> punkt1 {&arvud1};
    Punkt<2> punkt2 {&arvud2};
    std::cout << "P1: " << punkt1.toString() << '\n';
    std::cout << "P2: " << punkt2.toString() << '\n';
    std::cout << "P1 kaugus P2-st " << punkt1.kaugusPunktist(punkt2) << '\n';
    
    Sirgloik<Punkt<2>> sl1{&punkt1, &punkt2};
    std::cout << "Lõik: " << sl1.toString() << '\n';
    std::cout << "Lõigu pikkus: "<< sl1.pikkus() << '\n';
    return 0;
}