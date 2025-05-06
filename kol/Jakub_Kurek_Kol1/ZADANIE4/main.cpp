#include "klasa.h"
#include <iostream>

// ZADANIE 4
/* W pliku klasa.h jest zdefiniowana klasa o nazwie Litera
   Prosze tak rozwinac zawartosc plikow, aby dzialal ponizszy kod.

   Przyklad kompilowania:
   g++ -std=c++20 main.cpp klasa.cpp -o program
*/

// ---------------- ponizej prosze nic nie zmieniac -----------------
auto main() -> int {
    Litera k1('A');
    Litera k2 = k1;
    k1 = k2;
    std::cout << "Litery: " << k1.print() << " " << k2.print() << std::endl;
    return 0;
}
