///////////////////////
////// ZADANIE 2 //////
///////////////////////

// Napisz szablon funkcji `porownaj`, który porównuje dwie wartości dowolnego
// typu T. Funkcja ma wypisywać, która z wartości jest większa, mniejsza lub czy
// są równe (moze zwracać typ void).

// Funkcja ma działać dla:
// - typów liczbowych (int, double, itd.)
// - typu string (std::string)
// - typu const char* (porównując zawartość, NIE adresy)

// UWAGA: w przypadku typu `const char*`, użyj specjalizacji szablonu
// UWAGA: nie używaj std::max / std::min – porównania muszą być jawne

#include <compare>
#include <cstring>
#include <iostream>
#include <string>

// tutaj szablon funkcji
template <typename T> void porownaj(T lhs, T rhs) {
    auto cmp = lhs <=> rhs;
    if (cmp == std::strong_ordering::greater) {
        std::cout << "Lewa wartosc wieksza" << std::endl;
    } else if (cmp == std::strong_ordering::less) {
        std::cout << "Prawa wartosc wieksza" << std::endl;
    } else if (cmp == std::strong_ordering::equal) {
        std::cout << "Wartosci sa równe" << std::endl;
    }
}

// tutaj specjalizacja dla const char*
template <> void porownaj(const char* lhs, const char* rhs) {
    // Handling of null ptr as parameter
    if (lhs == nullptr || rhs == nullptr) {
        return;
    }

    auto cmp = std::strcmp(lhs, rhs);
    if (cmp > 0) {
        std::cout << "Lewa wartosc wieksza" << std::endl;
    } else if (cmp < 0) {
        std::cout << "Prawa wartosc wieksza" << std::endl;
    } else if (cmp == 0) {
        std::cout << "Wartosci sa równe" << std::endl;
    }
}

int main() {
    porownaj(5, 10);                                  // liczby
    porownaj(3.14, 3.14);                             // liczby równe
    porownaj(std::string("ala"), std::string("ola")); // string
    porownaj("pies", "pies");                         // const char*
    porownaj("kot", "pies");                          // const char*

    return 0;
}
