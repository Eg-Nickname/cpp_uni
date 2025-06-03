#include <iostream>
#include <stdexcept> // dla wyjątku w get()
#include <vector>

template <typename T> class A {
    std::vector<T> tablica;

    public:
    // konstruktor domyślny
    A() = default;
    // konstruktor kopiujący
    A(A<T> const& m);
    // operator przypisania
    A<T>& operator=(A<T> const& m);
    // kontrutkor przenoszący
    A(A<T>&& m);
    // operator przenoszacy
    A<T>& operator=(A<T>&& m);

    void put(T const&);
    T get() const;
};

// implementacja metody put
template <typename T> void A<T>::put(T const& m) { tablica.push_back(m); }

// konstruktor kopiujący
template <typename T>
A<T>::A(A<T> const& m)
    : tablica(m.tablica) // delegujemy do kopiującego konstruktora std::vector
{}

// operator przypisania kopiujący
template <typename T> A<T>& A<T>::operator=(A<T> const& m) {
    if (this != &m) {
        tablica = m.tablica;
    }
    return *this;
}

// konstruktor przenoszący
template <typename T>
A<T>::A(A<T>&& m)
    : tablica(std::move(
          m.tablica)) // delegujemy do kopiującego konstruktora std::vector
{}

// operator przypisania kopiujący
template <typename T> A<T>& A<T>::operator=(A<T>&& m) {
    if (this != &m) {
        tablica = std::move(m.tablica);
    }
    return *this;
}

// implementacja metody get
template <typename T> T A<T>::get() const {
    if (tablica.empty()) {
        throw std::out_of_range("Brak elementów w tablicy.");
    }
    return tablica.back(); // zwracamy ostatni element
}

int main() {
    A<int> obiekt1;
    obiekt1.put(10);
    obiekt1.put(20);

    A<int> obiekt2 = obiekt1; // użycie konstruktora kopiującego
    std::cout << "Ostatni element (obiekt2): " << obiekt2.get() << std::endl;

    A<int> obiekt3;
    obiekt3 = obiekt1; // użycie operatora przypisania
    std::cout << "Ostatni element (obiekt3): " << obiekt3.get() << std::endl;

    A<int> obiekt4(std::move(obiekt3));
    std::cout << "Ostatni element (obiekt4): " << obiekt4.get() << std::endl;
    A<int> obiekt5;
    obiekt5 = std::move(obiekt4);
    std::cout << "Ostatni element (obiekt5): " << obiekt5.get() << std::endl;
    // std::cout << "Ostatni element (obiekt3): " << obiekt3.get() << std::endl;
    // std::cout << "Ostatni element (obiekt4): " << obiekt4.get() << std::endl;

    return 0;
}
