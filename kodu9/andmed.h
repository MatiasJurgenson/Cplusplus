#ifndef ANDMED_H
#define ANDMED_H

#include <memory>


int *loo_andmed(int);
void tootle_andmeid(int*, int);
void kustuta_andmed(int*);

std::unique_ptr<int> genereeri_arv();
void proovi_arvu(std::weak_ptr<int>);

#endif