//g++ -std=c++20 -Werror ...
#include <iostream>

const int MAX_N = 1000;

double mySqrt(double n) {
    double alg = n / 2;

    for (int i = 0; i < MAX_N; ++i) {
        double r = n / alg;
        alg = (alg + r) / 2;
        double newAlg = (alg + r) / 2;
        double diff = std::abs(newAlg - alg) / alg;
        if (diff < 0.01) {
            alg = newAlg;
            break; 
        }

    }

    return alg;
}

void yl1 () {
    std::cout << mySqrt(25);

}

void yl2() {
    /*Mitme ülesande tulemus sisestada? 3
1. ülesande eest saadud punktisumma: 10
Maksimaalne võimalik punktide arv 1. ülesande eest: 10
2. ülesande eest saadud punktisumma: 7
Maksimaalne võimalik punktide arv 2. ülesande eest: 12
3. ülesande eest saadud punktisumma: 5
Maksimaalne võimalik punktide arv 3. ülesande eest: 8*/

    int ylesanded; 
    std::wcout << L"Mitme ülesande tulemus sisestada? ";
    std::cin >> ylesanded;



}

void printIstmeteTabel(bool istmed[6][4]) {
        for (int rida = 0; rida < 6; ++rida) {
            for (int veerg = 0; veerg < 4; ++veerg) {
                std::cout << static_cast<char>('A' + veerg) << ' ';
                if (istmed[rida][veerg]) {
                    std::cout << "X";
                
                }
            }

            std::cout << "\n";
        }
}

void yl3() {
    bool istmed[6][4];

}

int main() {
    //yl1();
    //yl2();
    return 0;
}