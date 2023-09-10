#ifndef KODU6_TOIT_H
#define KODU6_TOIT_H

#include <string>
#include <vector>
using std::ostream;

class Toit {
private:
    protected:
    std::string toiduNimetus{};
    float hind{};

public:
    Toit() = default;
    Toit(std::string m_toiduNimetus, float m_hind);
    virtual ~Toit() = default;

    std::string getToiduNimetus();
    void setToiduNimetus(std::string);

    virtual float getHind();
    void setHind(float);

    friend bool operator<=(const Toit& l, const Toit& r);
    friend ostream& operator<<(ostream& os, const Toit& a);

};

class KampaaniaToit : public Toit {
private:
    int soodustuseProtsent{};

public:
    KampaaniaToit() = default;
    KampaaniaToit(std::string m_toiduNimetus, float m_hind, int m_soodustuseProtsent);

    float getHind() override;

    friend bool operator<=(const KampaaniaToit& l, const KampaaniaToit& r);
    friend ostream& operator<<(ostream& os, const KampaaniaToit& t); 

};

float loe_toidud(std::string, std::vector<Toit> *viide);

#endif
