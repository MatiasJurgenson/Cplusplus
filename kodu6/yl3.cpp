// Kirjuta 3. ülesande lahendus siia.

#include "loomad.h"
#include <iostream>

int main() {
    Madu madu("Ma", 0);

    Loomad loom("Lo");
    loom = madu; //polümorfism

    madu.häälitsus(); //dünaamiline seostamine
    std::cout << loom << "\n";
    return 0;
}