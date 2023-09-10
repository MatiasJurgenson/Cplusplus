#include "stuff.h"
#include <iostream>

Tudeng::Tudeng(std::string nimi, std::string õppekava, std::map<std::string, int> ainepunktid) : m_nimi(nimi), m_õppekava(õppekava), m_ainepunktid(ainepunktid) {}

Tudeng lisa_üliõpilane(std::string andmed) {
    std::size_t split = andmed.find(" ");

    std::string nimi;
    std::string id;
    std::string aine;
    int punktid;
    std::map<std::string, int> aine_punktid;

    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            id = andmed.substr(0, split);

            andmed = andmed.substr(split + 1, andmed.length());
            split = andmed.find(" ");
        } else {
            nimi += andmed.substr(0, split);

            andmed = andmed.substr(split + 1, andmed.length());
            split = andmed.find(" ");
        }
    }

        
    while (split != std::string::npos) {
        aine = andmed.substr(0, split);

        andmed = andmed.substr(split + 1, andmed.length());
        split = andmed.find(" ");

        punktid = std::stoi(andmed.substr(0, split));

        andmed = andmed.substr(split + 1, andmed.length());
        split = andmed.find(" ");

        aine_punktid[aine] = punktid;            
    }

    Tudeng Tudeng(nimi, aine, aine_punktid);   
    
    return Tudeng;
}