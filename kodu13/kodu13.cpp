#include "kodu13.h"

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>


int main() {
    //ÜL1
    /*
    std::cout << "Sisesta täisarve, iga arv eraldi real:\n";
    std::map<int, int> numbrid;

    while (true) {
        std::string arv;
        std::cin >> arv;
        if (std::cin.eof()) {
                break;
            }
        try {
            int str_int = std::stoi(arv);
            ++numbrid[str_int];
        } catch (const std::exception& e) {
            std::cout << "Vigane sisend stoi\n";
        }
    }
    
    for (auto el : numbrid) {
        std::cout << el.first << " " << el.second << "\n";
    } 
    */

   //ÜL2

    std::fstream fail("fail.txt");

    if (!fail.is_open()) { // kui faili pole teeb tavaliselt
        std::string sisend;

        double arv1, arv2, arv3;
        std::cout << "Kordajad on: ";
        std::getline(std::cin, sisend);

        std::size_t split = sisend.find(" ");
        arv1 = std::stoi(sisend.substr(0, split));
        sisend = sisend.substr(split + 1, sisend.length());

        split = sisend.find(" ");
        arv2 = std::stoi(sisend.substr(0, split));
        sisend = sisend.substr(split + 1, sisend.length());

        arv3 = std::stoi(sisend);

        try {
            double tulemus = determinant(arv1, arv2, arv3);
            double x1 = (-arv2 - std::sqrt(tulemus)) / (2.0*arv1);
            double x2 = (-arv2 + std::sqrt(tulemus)) / (2.0*arv1);
            std::cout << "Ruutvõrrandi lahendid on: " << x1 << " ja " << x2;

        } catch (NegatiivneDeterminant<double>& e) {
            std::cout << e.m_sõnum << e.m_determinant;
            std::cout << "Reaalarvulist lahendit ei leidu!";
        }
    } else {

        std::string rida;

    while (getline(fail, rida)) {

        //.split() 
        double arv1, arv2, arv3;
        std::size_t split = rida.find(" ");

        arv1 = std::stoi(rida.substr(0, split));
        rida = rida.substr(split + 1, rida.length());

        split = rida.find(" ");
        arv2 = std::stoi(rida.substr(0, split));
        rida = rida.substr(split + 1, rida.length());

        arv3 = std::stoi(rida);

        try {
            double tulemus = determinant(arv1, arv2, arv3);
            double x1 = (-arv2 - std::sqrt(tulemus)) / (2.0*arv1);
            double x2 = (-arv2 + std::sqrt(tulemus)) / (2.0*arv1);
            std::cout << "Ruutvõrrandi lahendid on: " << x1 << " ja " << x2 << "\n";

            } catch (NegatiivneDeterminant<double>& e) {
            std::cout << e.what() << "\n";
            std::cout << "Reaalarvulist lahendit ei leidu!"<< "\n";
            }
       
        }

    }

    

    return 0;
}