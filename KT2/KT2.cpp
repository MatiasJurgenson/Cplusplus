#include "KT2.h"

int main() {
    std::vector<int> v1{12, 8, 12, 6, 14, 1, 3, 4};
    std::vector<int> v2{30, 10, 20};

    MinuMassiiv<int, false> massiiv(v2);

    std::cout << massiiv << "\n";

    massiiv.sorteeria();

    std::cout << massiiv << "\n";

    buss("buss.txt");

    return 0;
}