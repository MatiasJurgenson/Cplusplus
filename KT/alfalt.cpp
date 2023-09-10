#include "asfalt.h"
#include <cmath>

std::string ajakulu(float meeter) {
    int m = (int)ceil(meeter);
    m /= 2;
    if (m/60 > 8) { //480
        return "ajakulu ületab tööpäeva kestvuse";
    }

    return std::to_string(m/60) + " h " + std::to_string(m%60) + " min";
}

float teepikus(float laius, float liiter) {
    return liiter/3/laius;
}

std::string arvuta_ajakulu(float laius, float liiter) {
    return ajakulu(teepikus(laius, liiter));
}