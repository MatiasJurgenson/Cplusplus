#ifndef KODU3_KODU3_FUN_DEKL_H
#define KODU3_KODU3_FUN_DEKL_H

#include <iostream>
#include <string>

// Siia saad lisada funktsioonide päised

int fun(int, int);
int fun(double);
std::string fun(unsigned int, std::string);

double kehamassiindeks(double, int);
std::string hinnang(double);

std::string otsi_mustrit(int& argc, char* argv[]);

#endif