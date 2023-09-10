#include "kodu14.h"

#include <iostream>

int main() {
    std::vector<int> v{12, 8, 12, 6, 14, 1, 3, 4};
    int arv = 5;

    liida<int>(v, arv);

    for_each(v.begin(), v.end(), [](int &n){std::cout << n << " ";});
    std::cout << "\n";

    std::vector<std::string> vs{"kaks", "kolm", "neli"};
    std::string sõne = "kümmend"; 

    liida<std::string>(vs, sõne);

    for_each(vs.begin(), vs.end(), [](std::string &n){std::cout << n << " ";});
    std::cout << "\n";

    std::vector<int> v2{2, 6, 9, 12, 56, 23};
    std::vector<int> v3;

    vali(v2, 5, 15, v3);

    for_each(v3.begin(), v3.end(), [](int &n){std::cout << n << " ";});
    std::cout << "\n";

    return 0;
}