#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>


void yl1() {
    int x;

    std::cout << "Sisesta täisarv: ";
    std::cin >> x;
    //std::cout << "Sain " << x << "\n";
    std::cout << "Viimane number: " << (x % 10) << "\n";
    std::cout << "Arv nihutatult üks koht paremale: " << (x >> 1) << "\n";
    std::cout << "Tulemus nihutatult kaks kohta vasakule: " << (x << 2) << "\n";
}

void yl2() {
    int kaal, min;

    std::cout << "Sisesta kaal:";
    std::cin >> kaal;
    std::cout << "Sisesta aeg minutites:";
    std::cin >> min;
    std::cout << "Tegevus\tAeg min\tkulutatud kcal\n";

    std::cout << "------------------------------------------\n";

    //static_cast<double>
    std::cout << "Kõndimine\t" << min << "\t" << (kaal * 4 * (min / 60.0)) << "\n";
    std::cout << "Treppidel käimine\t" << min << "\t" << (kaal * 5.5 * (min / 60.0)) << "\n";
    std::cout << "Ujumine\t" << min << "\t" << (kaal * 10 * (min / 60.0)) << "\n";
    std::cout << "Korvpall\t" << min << "\t" << (kaal * 8 * (min / 60.0)) << "\n";

}

void yl3() {
    std::cout << "Sisesta ringi raadius: ";
    float r;
    std::cin >> r;
    
}

int main() {
    //yl1();
    //yl2();
    yl3();
    return 0;
}

//std::fixed std::setprecision(2)