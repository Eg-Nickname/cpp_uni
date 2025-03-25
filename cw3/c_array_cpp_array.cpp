// Zadanie tablice:

// Napisz program, w którym utworzysz tablicę o zadanej liczbie elementów. Niech
// program poprosi o wprowadzenie liczb, które następnie będą przechowywane w
// tej tablicy. Wypisz liczby przechowywane w tablicy. Oblicz sumę oraz średnią
// liczb, wypisz je na ekran.

// Zmodyfikuj program tak, aby zamiast prostej tablicy używał kontenera
// std::array.

#include <array>
#include <iostream>

void calculate_for_c_array(int tab[10]);
void calculate_for_cpp_array(std::array<int, 10> cpp_array);

auto main() -> int {
    int c_array[10];
    std::array<int, 10> cpp_array;

    for (int i = 0; i < 10; i++) {
        int liczba;
        std::cin >> liczba;
        c_array[i] = liczba;
        cpp_array.at(i) = liczba;
    }
    calculate_for_c_array(c_array);
    calculate_for_cpp_array(cpp_array);
    return 0;
}

void calculate_for_c_array(int tab[10]) {
    int sum = 0;
    double avg = 0.0;
    for (int i = 0; i < 10; i++) {
        std::cout << tab[i] << " ";
        sum += tab[i];
    }
    avg = (double)sum / 10.0;
    std::cout << std::endl
              << "Suma liczb w tablicy " << sum << ", średnia " << avg
              << std::endl;
}
void calculate_for_cpp_array(std::array<int, 10> cpp_array) {
    int sum = 0;
    double avg = 0.0;
    for (auto it = cpp_array.begin(); it < cpp_array.end(); it++) {
        std::cout << *it << " ";
        sum += *it;
    }
    avg = (double)sum / 10.0;
    std::cout << std::endl
              << "Suma liczb w array " << sum << ", średnia " << avg
              << std::endl;
}