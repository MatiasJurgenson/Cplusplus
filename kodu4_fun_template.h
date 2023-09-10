#ifndef KODU4_FUN_TEMPLATE_H
#define KODU4_FUN_TEMPLATE_H

#include <string>  

// Siia tulevad template funktsioonid koos sisuga

template<typename T, typename U>
T liida(T m1, U m2) {
    return m1 + m2;
}

template<typename ...T>
auto summa(T ...argumendid) {
    double summa = 0;
    for (auto argument : {argumendid...}) {
        summa += argument;
    }
    return summa;
}

template<auto T>
bool on_vahemikus(int a, int b) {
    if (a <= T && T <= b) {
        return true;
    } else {
        return false;
    }
}


// Teise ülesande funktsiooni deklaratsioon, sisu läheb cpp faili

void andmed_failist(std::string);


#endif
