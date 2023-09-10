#ifndef OSALEJAD_TULEMUSED_H
#define OSALEJAD_TULEMUSED_H

#include <string>
#include <vector>

class Osalenud {
public:
    virtual ~Osalenud() = default;

};

class Tulemus {
private:
    std::string m_isikukood;
    std::string m_voistluseNimi;
    int m_koht;

public:
    Tulemus(std::string, std::string, int);

    auto getIsikukood();
    auto getVoistluseNimi();
    auto getKoht();

    friend std::ostream& operator<<(std::ostream&, const Tulemus&);
}; 

class Osaleja : Osalenud {
private:
    std::string m_nimi;
    std::string m_isikukood;
    std::vector<Tulemus> m_tulemused;

public:
    ~Osaleja() override = default;
    Osaleja(std::string, std::string);

    auto getNimi();
    auto getIsikukood();

};


class Lapsosaleja {

};

void loe_failist(std::string, std::vector<Tulemus>);



#endif