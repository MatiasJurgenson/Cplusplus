#ifndef ARVUTUSED_H
#define ARVUTUSED_H

//ül 1

int liida_1(int, int, int);
int liida_2(int*, int*, int*);
int liida_3(int&, int&, int&);
int* liida_4(int*, int*, int*, int*); //neljas parameeter on summa asukoht
int& liida_5(int&, int&, int&, int&); //neljas parameeter on summa asukoht

//ül 2

int korruta_1(int [], int); 
int korruta_2(int*, int); // kasuta indekseid 
int korruta_3(int*, int); // kasuta viitade aritmeetikat 
int* korruta_4(int*, int, int*); // kasuta viitade aritmeetikat, kolmas parameeter on korrutise asukoht
int& korruta_5(int*, int, int&); // kasuta viitade aritmeetikat, kolmas parameeter on korrutise asukoht

#endif