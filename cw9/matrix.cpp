#include <array>
#include <iostream>
#include <stdexcept>

template <typename T, std::size_t ROWS, std::size_t COLS> class Matrix {
    private:
    std::array<std::array<T, COLS>, ROWS> data;

    public:
    // Konstruktor domyślny (opcjonalnie może nic nie robić)
    Matrix() {}

    // Metoda do wypełniania wartościami
    void fill(const T& value);

    // Dostęp do elementu z kontrolą zakresu
    T& at(std::size_t row, std::size_t col);
    const T& at(std::size_t row, std::size_t col) const;

    // Dodawanie dwóch macierzy
    Matrix<T, ROWS, COLS> operator+(const Matrix<T, ROWS, COLS>& other) const;

    // Wypisanie macierzy
    void print() const;
};

// Metoda do wypełniania wartościami
template <typename T, std::size_t ROWS, std::size_t COLS>
void Matrix<T, ROWS, COLS>::fill(const T& value) {
    for (auto rows = data.begin(); rows < data.end(); rows++) {
        for (auto pos = (*rows).begin(); pos < (*rows).end(); pos++) {
            *pos = value;
        }
    }
}

// Dostęp do elementu z kontrolą zakresu
template <typename T, std::size_t ROWS, std::size_t COLS>
T& Matrix<T, ROWS, COLS>::at(std::size_t row, std::size_t col) {
    if (row > ROWS) {
        throw std::out_of_range("Row out ofrange.");
    }
    if (col > COLS) {
        throw std::out_of_range("Col out ofrange.");
    }
    return this->data.at(row).at(col);
}

template <typename T, std::size_t ROWS, std::size_t COLS>
const T& Matrix<T, ROWS, COLS>::at(std::size_t row, std::size_t col) const {
    if (row > ROWS) {
        throw std::out_of_range("Row out ofrange.");
    }
    if (col > COLS) {
        throw std::out_of_range("Col out ofrange.");
    }
    return this->data.at(row).at(col);
}

// Dodawanie dwóch macierzy
template <typename T, std::size_t ROWS, std::size_t COLS>
Matrix<T, ROWS, COLS>
Matrix<T, ROWS, COLS>::operator+(const Matrix<T, ROWS, COLS>& other) const {
    Matrix<T, ROWS, COLS> result;
    for (std::size_t row = 0; row < ROWS; row++) {
        for (std::size_t col = 0; col < COLS; col++) {
            result.at(row, col) = this->at(row, col) + other.at(row, col);
        }
    }
    return result;
}

// Wypisanie macierzy
template <typename T, std::size_t ROWS, std::size_t COLS>
void Matrix<T, ROWS, COLS>::print() const {
    for (std::size_t row = 0; row < ROWS; row++) {
        for (std::size_t col = 0; col < COLS; col++) {
            std::cout << this->at(row, col) << ",";
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix<int, 2, 3> m1;
    m1.fill(1);

    Matrix<int, 2, 3> m2;
    m2.fill(2);

    Matrix<int, 2, 3> sum = m1 + m2;

    std::cout << "Macierz m1:\n";
    m1.print();

    std::cout << "Macierz m2:\n";
    m2.print();

    std::cout << "Suma m1 + m2:\n";
    sum.print();

    std::cout << "Element [1][2] sumy: " << sum.at(1, 2) << "\n";

    return 0;
}
