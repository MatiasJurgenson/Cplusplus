#include "stl.h"

#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <string>

int main() {

    std::vector<std::string> c1{"vector", "deque", "queue"};
    std::deque<std::string> c2{"list", "forward_list", "array"};
    std::list<std::string> d1;
    yhenda(c1, c2, d1);
    tryki(d1, std::cout);

    std::list<int> l1{1, 5, 3, 2, 1, 1, 1};
    std::list<int> l2{3, 5, 3, 9, 9};
    std::cout << std::boolalpha << (l1 < l2) << '\n';
    std::vector<int> v1{10, 11};
    std::vector<int> v2{3, 5, 3};
    std::cout << std::boolalpha << (v1 < v2) << '\n';

    return 0;
}