#ifndef PRAX14_H
#define PRAX14_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

/*
template <typename T>
class List {
private:
    T *m_Elems;
    size_t m_Size = 1;
    size_t m_Capacity

public:

    List() : m_Elems(new T[1]) {...}
    ~List();

    T &otsi(auto predikaat) {
        for (int i = 0; i < m_Size; 1++) {
            auto &elem = m_Elems[i];
            if (predikaat(elem))
        }
    }
};
*/

class Raamat {
private:
    std::string m_pealkiri{};
    std::string m_autor{};
    std::string m_sari{};
public:
    std::string get_pealkiri() {
        return m_pealkiri;
    }

    std::string get_autor() {
        return m_autor;
    }

    std::string get_sari() {
        return m_sari;
    }

    void set_sari(std::string uus_sari) {
        m_sari = uus_sari;
    }

    friend std::ostream& operator<<(std::ostream& os, const Raamat& a){
    os << a.m_autor << ". " << a.m_pealkiri << ", " << a.m_sari;
    return os;
    }

};

class Sari {
private:
    std::string m_nimi{};
    std::vector<Raamat> m_raamatud{};

public:
    void lisa_raamat(Raamat raamat) {
        m_raamatud.push_back(raamat);
    }

    void kustuta_raamat(Raamat raamat) {
        std::remove_if(m_raamatud.begin(), m_raamatud.end(), [&raamat](Raamat &i){ return raamat.get_autor() == i.get_autor() && 
        raamat.get_sari() == i.get_sari() && raamat.get_pealkiri() == i.get_pealkiri(); });
    }

    void väljasta_raamatud() {
        std::for_each(m_raamatud.begin(), m_raamatud.end(), [](Raamat &i){std::cout << i << "\n";});
    }

};

class sarjad {
private:
    std::map<std::string, std::vector<Raamat>*> sarjade_info{};

public:
    void lisa_raamat(Raamat raamat);

};

#endif