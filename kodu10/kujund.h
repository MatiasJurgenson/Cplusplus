#ifndef KUJUND_H
#define KUJUND_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

template <unsigned short const n> 
class Punkt{
private:
    std::vector<float>* m_kordinaadid{};

public:
    Punkt();
    Punkt(std::vector<float>* koordinaadid);
    ~Punkt();
    float kaugusPunktist(Punkt &punkt);
    std::string toString();
    std::vector<float>* getKoordinaadid();
};

/*
Punkt(Punkt &other) {
    m_coords = other.m_coords

Punkt(punkt &) = delete;    
}
*/

template <unsigned short const n> 
Punkt<n>::Punkt() {
    std::vector<float> *ptr = new std::vector<float> (n, 0);
    m_kordinaadid = ptr;
}

template <unsigned short const n> 
Punkt<n>::Punkt(std::vector<float>* koordinaadid) : m_kordinaadid(koordinaadid) {}

template <unsigned short const n> 
Punkt<n>::~Punkt() {
    delete m_kordinaadid;
}

template <unsigned short const n> 
float Punkt<n>::kaugusPunktist(Punkt<n> &punkt){
    //https://math.stackexchange.com/questions/3398405/is-the-distance-formula-applicable-for-4-dimensional-coordinate-system-if-yes
    float koordinaatide_summa = 0;
    for (int i = 0; i < n; i++) {
        koordinaatide_summa += (float)pow((punkt.getKoordinaadid()->at(i) - m_kordinaadid->at(i)), 2);
    }

    float kaugus = (float)sqrt(koordinaatide_summa);

	return kaugus;

}


template <unsigned short const n> 
std::string Punkt<n>::toString() {
    std::string väljund = "(";
    for (int i = 0; i < n-1; i++){
        väljund += std::to_string(m_kordinaadid->at(i)) + ", ";
    }   
    return väljund + std::to_string(m_kordinaadid->at(n-1)) + ")";
}

template <unsigned short const n> 
std::vector<float>* Punkt<n>::getKoordinaadid() {
    return m_kordinaadid;
}

template <typename T> 
class Sirgloik{
private:
    T* m_p1{};
    T* m_p2{};

public:
    Sirgloik(T* p1, T* p2);
    float pikkus();
    std::string toString();
    std::string getKoordinaadid();

};

template <typename T> 
Sirgloik<T>::Sirgloik(T* p1, T* p2) : m_p1(p1), m_p2(p2) {}

template <typename T> 
float Sirgloik<T>::pikkus(){
    return m_p1->kaugusPunktist(*m_p2);
}

template <typename T>
std::string Sirgloik<T>::toString() {
    return m_p1->toString() + " - " + m_p2->toString();
}

template <typename T>
std::string Sirgloik<T>::getKoordinaadid() {
    return &m_p1 + " " + &m_p2; //todo
}


#endif 