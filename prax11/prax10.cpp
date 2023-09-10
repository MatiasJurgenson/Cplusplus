#include "prax10.h"

#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>

int main() {
    std::vector<int> v1{10, 11, 5, 3, 3};
    std::vector<int> v2{3, 5, 3, 5, 1};
    std::vector<int> v3{};
    tryki(v1, std::cout); // kuvab elemendid ekraanile
    tryki(v2, std::cout);
    yhisosa(v1, v2, v3);
    std::cout << "v1 ja v2 ühisosa:\n";
    tryki(v3, std::cout);
    v3.clear();
    yhend(v1, v2, v3);
    std::cout << "v1 ja v2 ühend:\n";
    tryki(v3, std::cout);
    v3.clear();
    vahe(v1, v2, v3);
    std::cout << "v1 ja v2 vahe:\n";
    tryki(v3, std::cout);

    std::vector<int> c1;
    std::deque<int> c2;
    std::list<int> c3;

    täida(c1, 10000000);
    täida(c2, 10000000);
    täida(c3, 10000000);

    auto algus = std::chrono::high_resolution_clock::now();
    std::cout << summa1(c1) << "\n";
    auto lõpp = std::chrono::high_resolution_clock::now();
    auto aeg = std::chrono::duration_cast<std::chrono::milliseconds>(lõpp - algus);
    std::cout << aeg << "\n";


    algus = std::chrono::high_resolution_clock::now();
    std::cout << summa2(c1) << "\n";
    lõpp = std::chrono::high_resolution_clock::now();
    aeg = std::chrono::duration_cast<std::chrono::milliseconds>(lõpp - algus);
    std::cout << aeg << "\n";

    std::cout << summa1(c2) << "\n";
    std::cout << summa2(c2) << "\n";
    std::cout << summa2(c3) << "\n";
    
    return 0;
}