// Zadanie tablice:

// Napisz program, w którym utworzysz tablicę o zadanej liczbie elementów. Niech
// program poprosi o wprowadzenie liczb, które następnie będą przechowywane w
// tej tablicy. Wypisz liczby przechowywane w tablicy. Oblicz sumę oraz średnią
// liczb, wypisz je na ekran.

// Zmodyfikuj program tak, aby zamiast prostej tablicy używał kontenera
// std::array.

#include <array>
#include <iostream>

const int array_size = 10;

void calculate_for_c_array(int tab[array_size]);
void calculate_for_cpp_array(std::array<int, array_size> cpp_array);

auto main() -> int {
    int c_array[array_size];
    std::array<int, array_size> cpp_array;

    for (int i = 0; i < array_size; i++) {
        std::string input;
        double liczba = 0.0;
        std::cin >> input;
        try {
            liczba = std::stod(input);
        } catch (std::invalid_argument) {
            // ignore input process further
            liczba = 0.0;
        }
        c_array[i] = liczba;
        cpp_array.at(i) = liczba;
    }
    calculate_for_c_array(c_array);
    calculate_for_cpp_array(cpp_array);
    return 0;
}

void calculate_for_c_array(int tab[array_size]) {
    int sum = 0;
    double avg = 0.0;
    for (int i = 0; i < array_size; i++) {
        std::cout << tab[i] << " ";
        sum += tab[i];
    }
    avg = (double)sum / (double)array_size;
    std::cout << std::endl
              << "Suma liczb w tablicy " << sum << ", średnia " << avg
              << std::endl;
}
void calculate_for_cpp_array(std::array<int, array_size> cpp_array) {
    int sum = 0;
    double avg = 0.0;
    for (auto it = cpp_array.begin(); it < cpp_array.end(); it++) {
        std::cout << *it << " ";
        sum += *it;
    }
    avg = (double)sum / (double)array_size;
    std::cout << std::endl
              << "Suma liczb w array " << sum << ", średnia " << avg
              << std::endl;
}