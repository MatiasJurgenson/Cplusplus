#include "lugemine.h"
#include <iostream>

int main() {
    std::set<Hoia> s1{};
    s1 = loe_hoia("andmed1.txt", s1);
    for (auto el : s1) {
        std::cout << el << ' ';
    }
    std::cout << "\n";

    std::map<std::string, int> m1{};
    m1 = loe_failist("andmed2.txt", m1);
    for (auto el : m1) {
        std::cout << el.first << " : " << el.second << "\n";
    }


    return 0;
}