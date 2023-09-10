#ifndef JOOGID_H
#define JOOGID_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Hinnad {
    public:
    virtual double liitriHind() = 0;
    virtual double tellimuseHind() = 0;
    virtual ~Hinnad();
};

class Jook: public Hinnad {
protected:
    string nimetus;
    double hind;
    int maht;

public: 
    Jook(string, double, int);

    string getNimetus() {return nimetus;}
    double getHind() {return hind;}
    int getMaht() {return maht;}

    double liitriHind();
    double tellimuseHind();

    friend ostream& operator<<(ostream& os, const Jook& s);

};



class Pudelijook: public Jook {
protected:
    int tellitudArv;

public:
    Pudelijook(string, double, int, int);

    double tellimuseHind();

    friend ostream& operator<<(ostream& os, const Pudelijook& s);
};



class Vaadijook: public Jook {

public:
    Vaadijook(string, double, int);
    double liitriHind();
    double tellimuseHind();
    friend ostream& operator<<(ostream& os, Vaadijook& s);
};



void loe_joogid(string, vector<Pudelijook>*, vector<Vaadijook>*);



#endif