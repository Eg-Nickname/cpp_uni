// Zmodyfikuj program tak, aby używał kontenera std::vector.  W tym przypadku
// nie zadawaj wielkości kontenera na początku programu, ale dodawaj elementy
// dynamicznie do kontenera. Zdefiniuj komendę, która będzie oznaczać „koniec
// wprowadzania liczb”. Oprócz sumy i średniej elementów wypisz też wielkość
// kontenera. Co się stanie, jeśli użytkownik nie wprowadzi żadnej liczby?
// Sprawdzaj poprawność wprowadzonych danych.

// Zbadaj jaka jest różnica między metodami std::max_element std::min_element
// oraz std::max std::min

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void process_vector(std::vector<double> vec);

auto main() -> int {
    std::vector<double> cpp_vector;
    std::string input = "";
    std::cout << "Program pobiera liczby. \"end\" zakończy wprowadzanie."
              << std::endl;
    std::cin >> input;
    while (input != "end") {
        try {
            cpp_vector.push_back(std::stod(input));
        } catch (std::invalid_argument) {
            // ignore input process further
        }
        std::cin >> input;
    }
    process_vector(cpp_vector);
    return 0;
}

void process_vector(std::vector<double> vec) {
    double sum = 0, avg = 0;

    for (auto it = vec.begin(); it < vec.end(); it++) {
        std::cout << *it << " ";
        sum += *it;
    }
    avg = (double)sum / (double)vec.size();
    std::cout << std::endl
              << "Suma liczb w vectorze " << sum << ", średnia " << avg
              << " ilość liczb " << vec.size() << std::endl;
}

// std::max_elemnt zwraca największa wartość w podanym zakresie natomiast
// std::max przyjmuje tylko 2 wartości i zwraca większa z nich. std::min_element
// i std::min jak wcześniej tylko, że wartość najmniejszą / mniejszą