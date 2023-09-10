#include "andmed.h"	
#include <iostream>

int main() {

   auto arv = genereeri_arv();
   std::cout << *arv << '\n';
   arv = genereeri_arv();
   std::cout << *arv << '\n';
 
   auto eksisteerivArv = std::make_shared<int>(1);
   proovi_arvu(eksisteerivArv); // jagatud viidast tehakse automaatselt nõrk viit
 
   std::weak_ptr<int> wp;
   proovi_arvu(wp);

auto andmed = loo_andmed(10);
   for (int i = 0; i < 10; i++) {
       std::cout << andmed[i] << ' ';
   }
   std::cout << '\n';
   tootle_andmeid(andmed, 10);
 
   for (int i = 0; i < 10; i++) {
       std::cout << andmed[i] << ' ';
   }
   std::cout << '\n';
 
   kustuta_andmed(andmed);
 
   std::cout << loo_andmed(0) << '\n'; // peaks olema 0x0
   tootle_andmeid(nullptr, 0); // ei tohiks väljastada midagi

    return 0;
}
