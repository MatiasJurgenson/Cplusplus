#ifndef KODU6_MINUTAISARV_H
#define KODU6_MINUTAISARV_H

#include <iostream>
using std::ostream;

class MinuTaisarv {

private:
    protected: 
    int täisarv{};

public:
    MinuTaisarv() = default;
    MinuTaisarv(int ntäisarv);
    
    int getArv();
    void setArv(int);

    int operator[](int);
    friend ostream& operator<<(ostream& os, const MinuTaisarv& m);
};

#endif