#ifndef PAHUPIDIARV_H
#define PAHUPIDIARV_H

class PahupidiArv {
    int m_Arv{0};

public:
    explicit PahupidiArv(int arv);
    PahupidiArv() = default;
    ~PahupidiArv();

    PahupidiArv(const PahupidiArv &o);

    PahupidiArv &operator=(const PahupidiArv &o);

    int operator+(int arv); 

    int arv();
    void arv(int arv);
};


#endif