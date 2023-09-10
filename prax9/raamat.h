#ifndef RAAMAT_H
#define RAAMAT_H

#include <vector>
#include <memory>
#include <string>

class Kontrollija;

class Teos {
protected:
    std::string m_nimi;
    std::string m_tahis;
    std::shared_ptr<std::string> m_laenutajanimi;
    int m_paevadeArv;

public:
    Teos(std::string nimi, std::string tahis, std::shared_ptr<std::string> laenutajaNimi, int paevadearv);
    virtual bool kasHoidlast() = 0;

    virtual std::ostream &print(std::ostream &);
    friend std::ostream &operator<<(std::ostream &, Teos &);

    int laenutusaeg();
    float paevaneViivis();

    void arvutaViivis(std::shared_ptr<Kontrollija> kontrollija);

};

class Kontrollija {
public:
    virtual void salvestaViivis(std::shared_ptr<std::string> laenutajaNimi, std::string teoseNimi, float viivis) = 0;
};


class Ajakiri : public Teos {

};

class Raamat : public Teos {

};

class ViiviseHoidja : public Kontrollija {
protected:
    float m_viivis;
    std::vector<std::shared_ptr<std::string>>* m_nimed;

public:
    ViiviseHoidja(float viivis);
    ~ViiviseHoidja();

    void salvestaViivis(std::shared_ptr<std::string> laenutajaNimi, std::string teoseNimi, float viivis) override;

    auto getHoiatatavadLaenutajad() {
        return m_nimed;
    }
};

class SuurimaViiviseLeidja : public Kontrollija {
private:
    std::shared_ptr<std::string> m_laenutajaNimi;
    std::string m_teoseNimi;
    float m_viivis;

public:
    void salvestaViivis(std::shared_ptr<std::string> laenutajaNimi, std::string teoseNimi, float viivis) override;
    void saadaHoiatus();

};

std::vector<std::shared_ptr<Teos>> loeTeosed(const std::string &asukoht);

#endif 