#include "klasa.h"
#include <iostream>

// ZADANIE 5
/* W pliku klasa.h jest zdefiniowana klasa o nazwie Wyraz
   Prosze tak rozwinac zawartosc plikow, aby dzialal ponizszy kod.

   Przyklad kompilowania:
   g++ -std=c++20 main.cpp klasa.cpp -o program
*/

// ---------------- ponizej prosze nic nie zmieniac -----------------
auto main() -> int {
    Wyraz w1("hipopotam");
    Wyraz w2;
    Wyraz w3 = w1;

    w1.Print();
    w2.Print();
    w3.Print();

    return 0;
}
