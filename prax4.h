#ifndef PRAX4_H
#define PRAX4_H

#include <string>
#include <filesystem>

//const ei saa muuta + kõik mida ei saa muuta on hea tava teha const-iks
void sagedus(const std::string &asukoht); 
template<typename T, int N = 10>
T liidaJaPiira(T a, T b) {
    if (a + b < N) {
        return a+ b;
    } else {
        return N;
    }
}
template<typename T>
void looFailJaKirjuta(std::filesystem::path asukoht, T elemendid[], size_t arv) {
        
}

#endif