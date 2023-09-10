#ifndef KODU14_H
#define KODU14_H

#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void liida(std::vector<T>& v, T& lisa) {
    std::for_each(v.begin(), v.end(), [lisa](T &n){n += lisa; });
}

template<typename T>
void vali(std::vector<T>& v, T a, T b, std::vector<T>& v1) {
    std::copy_if(v.begin(), v.end(), std::back_inserter(v1), [a, b](int &i){ return a <= i && i <= b; });
}

#endif