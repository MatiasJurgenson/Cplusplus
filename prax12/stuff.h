#ifndef STUFF_H
#define STUFF_H

#include <string>
#include <vector>
#include <map>

class Tudeng {
private:
    std::string m_nimi{};
    std::string m_õppekava{};
    std::map<std::string, int> m_ainepunktid{};

public:
    Tudeng(std::string nimi, std::string õppekava, std::map<std::string, int> ainepunktid);
};

Tudeng lisa_üliõpilane(std::string andmed);

#endif