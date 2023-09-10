#include "minutaisarv.h"
#include <cmath>

MinuTaisarv::MinuTaisarv(int ntäisarv) : täisarv {ntäisarv} {}

int MinuTaisarv::getArv() {
    return täisarv;
}

void MinuTaisarv::setArv(int i) {
    täisarv = i;
}

 int MinuTaisarv::operator[](int i) {
    int tulemus = -1;
    if (täisarv / pow(10, i) < 1 && täisarv != 0) {
        return tulemus;
    }
    if (täisarv == 0 && i > 0) {
        return tulemus;
    }

    int number = täisarv;
    for (int j = 0; j <= i; j++) {
        tulemus = number % 10;
        number /= 10;
    }
    
    return tulemus;
 }

 ostream& operator<<(ostream& os, const MinuTaisarv& m){
    os << "MinuTaisarv: " << m.täisarv;
    return os;
}