#include <iostream>
#include <cmath>

//https://courses.cs.ut.ee/2023/cpp/Main/Praks8

int *eiTohi() {
    int *arv = new int;
    *arv = 100;
    return arv;
} // peale new asja tegemist kasuta delete

template<typename T>
void vaheta_ref(T &x, T &y) {
    T juhuslik = x;
    x = y;
    y = juhuslik;
}

template<typename T>
void vaheta_ptr(T *x, T *y) {
    auto temp = *x;
    *x = *y;
    *y = temp;
}

bool lahenda_1(double a, double b, double c, double& x1, double& x2) {
    if (a == 0 ) {
        return false;
    }

    auto D = pow(b, 2) - 4 * a * c;
    
    if (D < 0) {
        return false;
    }

    auto S = std::sqrt(D);

    x1 = (-b + S) / (2 * a);
    x2 = (-b - S) / (2 * a);
    
    return true;
}

bool lahenda_2(double *a, double *b, double *c, double& x1, double& x2) {
    if (*a == 0 ) {
        return false;
    }

    auto D = pow(*b, 2) - 4 * *a * *c;
    
    if (D < 0) {
        return false;
    }

    auto S = std::sqrt(D);

    x1 = (-*b + S) / (2 * *a);
    x2 = (-*b - S) / (2 * *a);
    
    return true;
}

int main() {
    /*
    int x = 10;
    int *y = &x;
    int z = *y;

    //viide
    int &c = x;
    int b = c;

    int *ptr = nullptr;
    //int &amp; ei saa nii
    */

    int x = 5, y = 7;
    vaheta_ref<int>(x, y);

    std::cout << x << ' ' << y << '\n';

    vaheta_ptr<int>(&x, &y);

    std::cout << x << ' ' << y << '\n';

    double a = 1.0, b = -2.0, c = 1.0;
    double x1, x2;       // lahendid on 1 ja 1
    if (lahenda_1(a, b, c, x1, x2))
        std::cout << "Lahendid on: " << x1 << ", " << x2 << '\n';
    else
        std::cout << "Reaalarvulisi lahendeid ei ole!" << '\n';

    double a2 = 1.0, b2 = -2.0, c2 = 1.0;
    double *ptra = &    a2, *ptrb = &b2, *ptrc = &c2;
    double x3, x4;
    if (lahenda_2(ptra, ptrb, ptrc, x3, x4))
        std::cout << "Lahendid on: " << x1 << ", " << x2 << '\n';
    else
        std::cout << "Reaalarvulisi lahendeid ei ole!" << '\n';


    //double ************************************************************************p = &a2;
}