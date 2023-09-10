#ifndef KODU13_H
#define KODU13_H

#include <exception>
#include <string>

template <typename T>
class NegatiivneDeterminant : public std::exception {
public:
    std::string m_sõnum{};
    T m_determinant{};

    auto what() {
        return m_sõnum + std::to_string(m_determinant);
    }

    NegatiivneDeterminant(std::string sõnum, T determinant) : m_sõnum(sõnum), m_determinant(determinant) {}    
};

template <typename T>
T determinant(T a, T b, T c) {
    auto determinant =  b*b - 4*a*c;
    if (determinant < 0) {
        throw NegatiivneDeterminant("Negatiivne determinant: ", determinant);
    }
    return determinant;
}

#endif