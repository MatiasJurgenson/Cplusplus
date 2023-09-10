#ifndef LOOMAD_H
#define LOOMAD_H

#include <string>
using std::ostream;

class Loomad {
private:
    std::string nimi{};

public:
    Loomad(std::string m_nimi);

    virtual void häälitsus();
    friend ostream& operator<<(ostream& os, const Loomad& l);

};

class Roomajad : public Loomad {
private:
    int jalgadeArv{};

public:
    Roomajad(std::string m_nimi, int m_jalgadeArv);

};

class Madu : public Roomajad {
public:
    Madu(std::string m_nimi, int m_jalgadeArv);

    virtual void häälitsus();
};



#endif