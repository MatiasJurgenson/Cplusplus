#include "arvutused.h"

int liida_1(int a, int b, int c) {
    return a + b + c;
}
int liida_2(int* a, int* b, int* c) {
    return *a + *b + *c;
}
int liida_3(int& a, int& b, int& c) {
    return a + b + c;
}
int* liida_4(int* a, int* b, int* c, int* summa) { //neljas parameeter on summa asukoht
    *summa = *a + *b + *c;
    return summa;
} 
int& liida_5(int& a, int& b, int& c, int& summa) { //neljas parameeter on summa asukoht
    summa = a + b + c;
    return summa;
} 

//ül 2

int korruta_1(int A[] , int b) {
    int summa = 1;
    for (int i = 1; i < b; i += 2) {
        summa *= A[i];
    } 
    return summa;
}
int korruta_2(int* A, int b) { // kasuta indekseid 
    int summa = 1;
    for (int i = 1; i < b; i += 2) {
        summa *= A[i];
    }
    return summa;
}
int korruta_3(int* A, int b) { // kasuta viitade aritmeetikat
    int summa = 1;
    A++;
    for (int i = 1; i < b; i += 2) {
        summa *= *A;
        A += 2;
    }
    return summa;
}
int* korruta_4(int* A, int b, int* summa) { // kasuta viitade aritmeetikat, kolmas parameeter on korrutise asukoht
    A++;
    for (int i = 1; i < b; i += 2) {
        *summa *= *A;
        A += 2;
    }
    return summa;
}
int& korruta_5(int* A, int b, int& summa) { // kasuta viitade aritmeetikat, kolmas parameeter on korrutise asukoht
    A++;
    for (int i = 1; i < b; i += 2) {
        summa *= *A;
        A += 2;
    }
    return summa;
}