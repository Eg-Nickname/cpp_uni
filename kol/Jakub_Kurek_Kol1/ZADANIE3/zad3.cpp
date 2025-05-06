// ZADANIE 3
/*
Ponizej podana jest lista stringow, zainicjalizowana kilkoma wartosciami.
Dodaj do tej listy na poczatek i na koniec kilka slow - patrz dokumentacja
kontenera list i lista jego funkcji.
Nastepnie wypisz na ekran cala liste dowolna metoda.
Wlacz potrzebne naglowki.
*/

#include <iostream>
#include <list>
#include <string>

auto main() -> int {
    std::list<std::string> lista{"aaa", "ccc", "bbb", "DDD",
                                 "rrr", "ZZZ", "uuu"};

    // tutaj napisz dalsza czesc programu...
    lista.push_front("Front1");
    lista.push_front("Front2");
    lista.push_front("Front3");
    lista.push_front("Front4");
    lista.push_back("Back1");
    lista.push_back("Back2");
    lista.push_back("Back3");
    lista.push_back("Back4");
    for (auto str : lista) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
