#include "raamat.h"

#include <iostream>
#include <memory>

int main() {
    auto hoiataja = std::make_shared<ViiviseHoidja>(0.2);
    hoiataja->salvestaViivis(std::make_shared<std::string>("Matias"), "Kevade", 4);

    return 0;
}