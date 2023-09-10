#include "kodu4_fun_template.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// NB! Kompileerimisel kasutada lippe: -Wall -Werror -Wpedantic -Wconversion

// Teise ülesande funktsiooni deklaratsioon

void andmed_failist(std::string faili_nimi){
    std::fstream fail(faili_nimi);

    //uus fail ja selle avamine
    std::ofstream fail2("tulemused.txt"); // kindlasti ofstream
    
     

    std::string rida;
    double summa = 0;
    double arv;
    
    while (getline(fail, rida)) {  
        //std::cout << "Lugesin failist rea: '" << rida << "'\n";

        //.split() 
        std::size_t split = rida.find(";;");

        int rea_arvude_arv = 0;
        double rea_summa = 0;

        while (split != std::string::npos) {
            
            //std::cout << rida.substr(0, split) << "\n";
            arv = std::stod(rida.substr(0, split));
            ++rea_arvude_arv;
            rea_summa += arv;
            rida = rida.substr(split + 2, rida.length());
            //std::cout << rida << "\n";
            split = rida.find(";;");
        }
        
        arv = std::stod(rida);
        ++rea_arvude_arv;
        rea_summa += arv;
        summa += rea_summa;
        double rea_keskmine = rea_summa / rea_arvude_arv;
        fail2 << rea_keskmine << "\n";

        

        
         
    }
    fail2 << summa;
        
}



#if !defined(VPL_TEST)
int main() {
    // Testi oma funktsioone siin

    
    std::cout << liida<int, int>(1, 2) << "\n";
    //std::cout << liida<std::string, int>("1", 2);
    std::cout << liida<std::string, std::string>("1", "2") << "\n";
    //std::cout << liida<int, double>(1, 2);

    std::cout << summa<int>(1) << "\n";
    
    std::cout << on_vahemikus<5>(1, 10) << "\n";
    // Automaatkontrollis kommenteeritakse main funktsioon välja
    

   andmed_failist("fail.txt");



}
#endif