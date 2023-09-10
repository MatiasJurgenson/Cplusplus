#include "KT.h"
#include "joogid.h"

#include <iostream>
#include <cmath>
#include <fstream>

//ÜL 1

std::string mytsi_number(int cm) {
    if (cm >= 52 && cm <= 64) {
        int juurde = cm - 49;
        std::string suurus = std::to_string(6 + juurde / 8) + " " + std::to_string(juurde % 8) + "/8";
        return suurus;

    }
    return "POLE";
}

std::string arvuta_mytsi_number(float kaal, float pikkus) {
    int peaÜmbermõõt = (int)(log10f(kaal/pikkus)*35.3);
    return mytsi_number(peaÜmbermõõt);

}

//ÜL 2

void loe_failist(std::string failiNimi) {

    //faili avamine
    std::fstream fail(failiNimi);

    //tulemused
    std::ofstream tulemused("tulemus.txt");
    std::ofstream ylejaak("ylejaak.txt");

    std::string rida;
    int arv;
    int index = 0;

    while (getline(fail, rida)) {
        if (rida.length() == 1) {
            arv = std::stoi(rida);
            continue;
        }

        if (index++ < arv) {

            //leiab 1 koordi
            std::size_t split = rida.find(",");
            double koord1 = std::stod(rida.substr(0, split));
            rida = rida.substr(split + 1, rida.length());

            //leiab 2 koordi
            split = rida.find(";");
            double koord2 = std::stod(rida.substr(0, split));
            rida = rida.substr(split + 1, rida.length());

            //leiab 3 koordi
            split = rida.find(",");
            double koord3 = std::stod(rida.substr(0, split));
            rida = rida.substr(split + 1, rida.length());

            //leiab 4 koordi
            split = rida.find(";");
            double koord4 = std::stod(rida.substr(0, split));
            rida = rida.substr(split + 1, rida.length());

            split = rida.find(";");
            double pikkus = std::stod(rida.substr(0, split));

            float kaugus = (float)sqrt(pow((koord3 - koord1), 2) + pow((koord4 - koord2), 2));

            if (kaugus < pikkus) {
                tulemused << "true\n";
            } else {
                tulemused << "false\n";
            }
        } else {
            ylejaak << rida;
        }
        
    }
}

int main(int argc, char *argv[]) {

    //ÜL 1

    std::cout << mytsi_number(53) << "\n";

    float kaal = std::stof(argv[1]);
    float pikkus = std::stof(argv[2]);

    std::cout << arvuta_mytsi_number(kaal, pikkus) << "\n";
    std::cout << "-----------------------------\n";

    //ÜL 2

    loe_failist("sisend.txt");

    return 0;

    //ÜL 3
    vector<Pudelijook>* joo = new vector<Pudelijook>;
    vector<Vaadijook>* joos = new vector<Vaadijook>;
    loe_joogid("joogid.txt", joo, joos);
    double pudeliteHind = 0;
    int s = 0;
    for (auto i = joo->begin(); i != joo->end(); i++) {
        cout << *i <<'\n';
        pudeliteHind += joo->at(s).tellimuseHind();
        s++;
    }
    cout << "Pudelijookide tellimuse hind: " << pudeliteHind << '\n';
    
    double vaadiHind = 0;
    s = 0;
    for (auto i = joos->begin(); i != joos->end(); i++) {
        cout << *i << '\n';
        vaadiHind += joos->at(s).tellimuseHind();
        s++;
    }
    cout << "Vaadijookide tellimuse hind: " << vaadiHind << '\n';
    cout << "Tellimus kokku: " << (vaadiHind+pudeliteHind);

    

    //vector<Jook*> joogid;
    //loe_joogid("joogid.txt", dynamic_cast<Pudelijook*>(joogid), joogid);
};