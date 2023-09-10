#include "joogid.h"


Hinnad::~Hinnad() {}

Jook::Jook(string a, double b, int c): nimetus {a}, hind {b}, maht {c} {}

double Jook::liitriHind() {
    return 1000*hind/maht;
}

double Jook::tellimuseHind() {
    return 0;
}

ostream& operator<<(ostream& os, const Jook& s){
    os << s.nimetus << " - pudeli hind on " << s.hind << "ja maht on " << s.maht;
    return os;
}




Pudelijook::Pudelijook(string a, double b, int c, int d): Jook(a, b, c), tellitudArv {d} {}

double Pudelijook::tellimuseHind() {
    return hind*tellitudArv;
}

ostream& operator<<(ostream& os, const Pudelijook& s){
    os << "Nimi: " <<s.nimetus << " hind: " << s.hind << " maht: " << s.maht << " pudelijook: pudelite arv: " << s.tellitudArv;
    return os;
}




Vaadijook::Vaadijook(string a, double b, int c): Jook(a, b, c) {}

double Vaadijook::liitriHind() {
    return 10*hind;
}

double Vaadijook::tellimuseHind() {
    return hind*maht/100;
}

ostream& operator<<(ostream& os, Vaadijook& s){
     os << "Nimi: " <<s.getNimetus() << " hind: " << s.getHind() << " maht: " << s.getMaht() << " vaadijook: liitri hind: " << s.liitriHind();
    return os;
}




void loe_joogid(string failiNimi, vector<Pudelijook>* pudel, vector<Vaadijook>* vaat) {
    ifstream infile(failiNimi);
    string rida;
  

    if (infile) {

        std::ofstream out("tulemus.txt");

        while (getline(infile, rida)) { //vÃµtab rea
            string sub;
            std::stringstream ss(rida);
            vector<string> ridaVektor;
            while (getline(ss, sub, ',')) { //eraldab ; juurest
                ridaVektor.push_back(sub);
            }

            if (ridaVektor.size() == 3) {
                vaat->push_back(Vaadijook(ridaVektor[0], stod(ridaVektor[1]), stoi(ridaVektor[2])));
            }
            else {
                pudel->push_back(Pudelijook(ridaVektor[0], stod(ridaVektor[1]), stoi(ridaVektor[2]), stoi(ridaVektor[3])));
            }
            
        }
        out.close();

    }
}