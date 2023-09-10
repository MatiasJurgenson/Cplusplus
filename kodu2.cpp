#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <string>

void kolmnurk() {

    //std::cout << "sisestage kolmnurga kõrgus: ";
    int n;
    std::cin >> n;

    for (size_t i{1}; i <= n; ++i) {
        std::string rida(i, '*');
        std::cout << rida << "\n";
    }
    
    for (int i{n-1}; i > 0; --i) {
        std::string rida(i, '*');
        std::cout << rida << "\n";
    }
}

void tabel() {
    double algus;
    double samm;
    double lopp;

    std::cout << "Sisestage algus: ";
    std::cin >> algus;
    std::cout << "Sisestage samm: ";
    std::cin >> samm;
    std::wcout << L"Sisestage lõpp: ";
    std::cin >> lopp;

    std::cout << "Nael\tKg\n";
    std::cout << "------------------\n";
    std::cout << std::fixed;

    double KgNael = 0.45359237;
    while (algus <= lopp) {
        double Kg = algus * KgNael;
        std::cout << std::setprecision(1) << algus << "\t" << std::setprecision(5) <<Kg <<"\n";
        algus += samm;
    }

}

void blackjack() {
    std::vector<int> kaardid(10);

    int seis = 0;
    int kaart;

    while (true) {

        while (true) {
                
            std::random_device generator;
            std::uniform_int_distribution<int> distribution(2,11);
            kaart = distribution(generator);

            if (kaardid[kaart - 2] < 4) {
                kaardid[kaart - 2] += 1;
                break;
            }
            else {
                continue;
            }  

        } 

        seis += kaart;


        if (seis >= 21) {
            if (seis > 21) {
                std::cout << "Tuli kaart: " << kaart << " hetkeseis: " << seis << "\nKahjuks kaotasid.";
                break;
            }
            else {
                std::wcout << "Tuli kaart: " << kaart << " hetkeseis: " << seis << L"\nVõitsid!";
                break;
            }
        }

        std::string vastus;

        std::cout << "Tuli kaart: " << kaart << " hetkeseis: " << seis << "\nKas soovid kaarti j/e? ";
        std::cin >> vastus;

        if (vastus == "e") {
            std::wcout << L"Lõppseis: " << seis << std::endl;
            break;
        }
        

    
    }
}

#if !defined(VPL_TEST)
int main() {
    // Testi oma funktsioone siin
    // kolmnurk();
    // tabel();
    blackjack();
}
#endif