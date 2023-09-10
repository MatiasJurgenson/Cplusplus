#include "arvutused.h"

#include <iostream>

#if !defined(VPL_TEST)
int main() {

    int a1 = 1, b1 = 2, c1 = 3, summa = 0;

    std::cout << liida_1(a1, b1, c1) << "\n";
    std::cout << liida_2(&a1, &b1, &c1) << "\n";
    std::cout << liida_3(a1, b1, c1) << "\n";
    std::cout << *liida_4(&a1, &b1, &c1, &summa) << "\n";
    std::cout << liida_5(a1, b1, c1, summa) << "\n";

    int A[] = {1, 2, 3, 4, 5};  
    int summa2 = 1;
    std::cout << korruta_1(A, 5) << "\n";
    std::cout << korruta_2(A, 5) << "\n";
    std::cout << korruta_3(A, 5) << "\n";
    std::cout << *korruta_4(A, 5, &summa2) << "\n";
    std::cout << korruta_5(A, 5, summa2) << "\n";
 
}
#endif