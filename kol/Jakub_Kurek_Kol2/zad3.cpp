///////////////////////
////// ZADANIE 3 //////
///////////////////////

#include <cstring>
#include <iostream>

// W poniższej klasie zaimplementuj konstruktor i operator
// przeniesienia tak, aby program main działał.

// Zwroc uwage, ze do spelnienia "rule of five" brakuje jeszcze
// konstruktora kopiujacego i operatora przypisania kopiujacego,
// ale na potrzeby tego zadania ich implementacja zostala pominięta.

class Wyraz {
    private:
    char *wptr;
    int len;

    public:
    Wyraz(const char *wyraz) : wptr(nullptr), len(0) {
        if (wyraz != nullptr) {
            len = strlen(wyraz);
            wptr = new char[len + 1];
            strcpy(wptr, wyraz);
        }
    }

    ~Wyraz() { delete[] wptr; };

    void print() const {
        if (wptr)
            std::cout << wptr << std::endl;
        else
            std::cout << "(pusty)" << std::endl;
    }

    // Tutaj konstruktor przeniesienia:
    Wyraz(Wyraz &&w) : wptr(w.wptr), len(w.len) {
        w.wptr = nullptr;
        w.len = 0;
    }

    // Tutaj operator przypisania przenoszący:
    Wyraz &operator=(Wyraz &&w) {
        if (this != &w) {
            if (this->wptr != nullptr) {
                delete[] this->wptr;
            }
            this->len = w.len;
            this->wptr = w.wptr;

            w.wptr = nullptr;
            w.len = 0;
        }
        return *this;
    }
};

int main() {
    Wyraz wyraz_1("kolokwium");
    Wyraz wyraz_2("c++");
    Wyraz wyraz_3("holahola");

    wyraz_1.print();
    wyraz_2.print();
    wyraz_3.print();

    Wyraz wyraz_4 = std::move(wyraz_1);
    wyraz_2 = std::move(wyraz_3);

    wyraz_1.print();
    wyraz_2.print();
    wyraz_3.print();
    wyraz_4.print();

    return 0;
}
