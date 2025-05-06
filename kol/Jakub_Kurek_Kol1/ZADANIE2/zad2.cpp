// ZADANIE 2
/*
W ponizszym programie podana jest tablica znakow t, zainicjalizowana kilkoma
wartosciami. 1) Utworz wektor std::vector<char> zawierajacy typ char i za pomoca
konstruktora zainicjalizuj go zawartoscia tej tablicy (patrz dokumentacja klasy
vector i lista jej konstruktorow) 2) Nastepnie za pomoca iteratora strumienia
wyjsciowego ostream_iterator oraz funkcji copy wypisz cala zawartosc tego
wektora na ekran, przedzielajac kazda literke przecinkiem ",". 3) Nastepnie
zastosuj funkcje sort, sortujac w kolejnosci odwrotnej do alfabetycznej i wypisz
raz jeszcze wektor na ekran. Wlacz potrzebne naglowki.
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
auto main() -> int {
    char t[] = {'f', 'e', 'y', 's', 'w', 'h', 'o', 'p', 'r', 'a'};

    // tutaj napisz dalsza czesc programu...
    std::vector<char> vec(std::begin(t), std::end(t));

    // Display using copy and osstream it
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<char>(std::cout, ","));
    std::cout << std::endl;

    // Sort vec
    std::sort(vec.begin(), vec.end(), std::greater<char>());

    // Display reversed vec
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<char>(std::cout, ","));
    std::cout << std::endl;

    return 0;
}
