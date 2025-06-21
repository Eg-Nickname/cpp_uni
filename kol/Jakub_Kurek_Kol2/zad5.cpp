///////////////////////
////// ZADANIE 5 //////
///////////////////////

#include <iostream>
#include <stdexcept>

// Funkcja dzielenie ma odpowiadac za dzielenie liczb
// calkowitych, tak ze wynik rowniez ma byc calkowity.
// Zaimplementuj wyjatek zapewniajacy, ze dzialania,
// w ktorych reszta z dzielenia bylaby niezerowa
// beda uznawane za niedozwolone.
// Pamietaj rowniez o dzieleniu przez 0
// Wykorzystaj dwa rozne wyjatki standardowe (patrz std::exception i stdexcept)
// W funkcji main zaimplementuj odpowiednio obsluge wyjatkow

// Pamietaj o zalaczeniu koniecznych naglowkow

int dzielenie(int a, int b) {
    // Dzielenie przez 0
    if (b == 0) {
        throw std::logic_error("Dzielenie przez zero");
    }
    // Dzielenie nie calkowite
    if (a % b != 0) {
        throw std::invalid_argument(
            "Prawa strona nie moze calkowicie podzielic lewej");
    }

    return a / b;
}

int main() {
    int c = 0;
    int d = 0;
    int e = 0;

    try {
        c = dzielenie(20, 2);
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::logic_error &e) {
        std::cout << "Logic error: " << e.what() << std::endl;
    }

    try {
        d = dzielenie(10, 3);
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::logic_error &e) {
        std::cout << "Logic error: " << e.what() << std::endl;
    }

    try {
        e = dzielenie(8, 0);
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::logic_error &e) {
        std::cout << "Logic error: " << e.what() << std::endl;
    }

    std::cout << "Wyniki: " << c << "\t" << d << "\t" << e << std::endl;

    return 0;
}
