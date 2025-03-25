// Zbadaj zachowanie iteratora w kontenerze wektor: zadeklaruj vector i wypełnij
// go dowolnymi danymi. Następnie pobierz iterator do dowolnego elementu, np.
// pierwszego i wypisz wartość na który on wskazuje. Następnie dopisz kilka
// elementów do vectora i ponownie wypisz wartość na którą wskazuje pobrany
// wcześniej iterator. Co stało się z iteratorem? Czy wskazuje on na poprawne
// dane, uległ „przesunięciu”, wskazuje na end() lub może zupełnie niepoprawne
// dane? Zweryfikuj swoje ustalenia z dokumentacją. Jeśli zachowanie iteratora
// jest niepożądane, zaproponuj inny kontener, który będzie w takiej sytuacji
// zachowywał się poprawnie i zademonstruj jego działanie.

#include <iostream>
#include <vector>

auto main() -> int {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto vec_it = vec.begin();
    std::cout << "Wartosc iteratora " << *vec_it << " capacity "
              << vec.capacity() << std::endl;

    for (int i = 6; i < 10; i++) {
        vec.push_back(i);
    }

    std::cout << "Wartosc iteratora po dodaniu elementu " << *vec_it
              << " capacity " << vec.capacity() << std::endl;

    return 0;
}

// Iterator nie wskazuje na poprawne dane ponieważ po dodaniu wystarczającej
// liczbie  elementów do vetora zostaje on powiekszony i przeniesiony