// ZADANIE 1
/*
W programie mamy tablice typu char.
Tablica jest zrobiona na typie std::array, ktory ma skladowe metody takie
jak begin(), end() czy size().
Napisz ponizej cztery rodzaje petli przebiegajacych
po calym zakresie tablicy i wypisujacych jej zawartosc na ekran. Powinny to byc:
1) zwykla petla for z indeksem roboczym,
2) petla while
3) petla for "po calym zakresie", tzw. range-based loop (z nowa skladnia),
4) petla z pomoca iteratorow, czyli auto it = tab.begin() etc.
Wlacz takze konieczne naglowki.
*/

#include <array>
#include <iostream>
auto main() -> int {
    std::array<char, 14> tab = {'Z', 'o', 'r', 'r', 'o', '-', 'c',
                                'a', 'r', 'r', 'a', 'm', 'b', 'a'};

    // tu napisz petle wypisujace elementy tablicy
    for (int i = 0; i < tab.size(); i++) {
        std::cout << tab[i];
    }
    std::cout << std::endl;

    int j = 0;
    while (j < tab.size()) {
        std::cout << tab[j];
        j++;
    }
    std::cout << std::endl;
    for (auto c : tab) {
        std::cout << c;
    }
    std::cout << std::endl;

    for (auto it = tab.begin(); it < tab.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
