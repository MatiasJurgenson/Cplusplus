#include "andmed.h"	
#include <random>
#include <iostream>

int *loo_andmed(int a) {
    if (a < 1) {
        return nullptr;
    }

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 100);

    int *pointer = new int [a];

    for (int i = 0; i < a; i++) {
        
        pointer[i] = distribution(generator);
    }
    return pointer;
}

void tootle_andmeid(int* A, int a){
    if (A == nullptr) {
        return;
    }
    int* ptr = A;
    int summa = 0;
    for (int i = 0; i < a; i++) {
        summa += *ptr; 
        *ptr *= -1;
        ptr++;
    }
    std::cout << "Summa: " << summa << "\n";
    std::cout << "Keskmine: " << (summa / a) << "\n";    
}

void kustuta_andmed(int* A) {
    delete A;
}


std::unique_ptr<int> genereeri_arv(){
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 100);
    std::unique_ptr<int> arv(new int(distribution(generator)));
    return arv;
}

void proovi_arvu(std::weak_ptr<int> nõrk){
    if (!nõrk.expired()) {
        std::cout << *nõrk.lock() << "\n";  
    } else {
        std::cout << "ei eksisteeri\n";
    }
}