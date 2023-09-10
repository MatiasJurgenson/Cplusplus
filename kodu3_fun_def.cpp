#include "kodu3_fun_dekl.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


//ül1

int fun(int a, int b) {
    return a + b;
}

int fun(double a) {
    return int (round(pow(a, 2)));
}

std::string fun(unsigned int a, std::string b) {
    std::string korruta = "";
    for (unsigned int i = 0; i < a; ++i) {
        korruta += b;
    }
    return korruta;
}


//ül2

double kehamassiindeks(double a, int b) {
    return b / pow(a, 2);
}

std::string hinnang(double a) {
    std::string vastus = "";
    if (a >= 30) {
        vastus = "rasvumine";
    }
    else if (a >= 25) {
        vastus = "ülekaal";
    }
    else if (a >= 19) {
        vastus = "normaalkaal";
    }
    else {
        vastus = "alakaal";
    }
    return vastus;
}


//Ül3
std::string otsi_mustrit(int& argc, char* argv[]) {
    std::string lause = "";

    for (int i = 1; i < argc; ++i) {
        lause += argv[i];
        if (i == argc - 1) {
            break;
        }
        else {
            lause += " ";
        }
        
    }

    std::size_t otsi = lause.find("-otsi=");
    if ((otsi == std::string::npos) || (lause.substr(otsi, 7) == "-otsi=")) {
        return "Mustrit ei ole olemas.";
    }

    int pikkus = 0;
    for (int i = 1; i < argc; ++i) {
        std::string sone = argv[i];
        std::size_t otsi = sone.find("-otsi=");
        if (otsi != std::string::npos) {
            pikkus = int (sone.size()) - 6;
            
        }
    }

    std::string otsitav = lause.substr(otsi+6, pikkus);

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == otsitav) {
            return "Otsitav '" + otsitav + "' leiti.";
        }
    }
    

    return "Otsitavat '" + otsitav + "' ei leitud.";
}

#if !defined(VPL_TEST)
int main(int argc, char *argv[]) {

    /*
    //ül1
    std::cout << fun(2, 3) << "\n";
    std::cout << fun(3.5) << "\n";
    std::cout << fun(10, "C++") << "\n"; 

    ül2
    double pikkus = std::stod(argv[1]);
    int kehakaal = std::stoi(argv[2]);
    double kmi{kehamassiindeks(pikkus, kehakaal)};
    std::cout << "kmi: " << kmi << " hinnang: "<< hinnang(kmi) << '\n';

    */

    //ül3
    std::cout << otsi_mustrit(argc, argv);
    

    
}
#endif