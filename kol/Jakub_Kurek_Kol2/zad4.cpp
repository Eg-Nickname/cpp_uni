///////////////////////
////// ZADANIE 4 //////
///////////////////////

#include <iostream>
#include <memory>

// w ponizszym programie zamien wszystkie raw pointery
// na odpowiednie smart pointery

// wypisz wartości przechowywane w c_1, c_2 oraz c_3.
// W tym celu przeładuj operator << w klasie Cyferka.

// pamietaj o zalaczeniu koniecznych naglowkow

class Cyferka {
    private:
    int c;

    public:
    Cyferka(int i) : c(i) {};
    ~Cyferka() {};
    friend std::ostream &operator<<(std::ostream &stream, const Cyferka &cyfra);
};

std::ostream &operator<<(std::ostream &stream, const Cyferka &cyfra) {
    return stream << cyfra.c;
}

int main() {
    std::unique_ptr<Cyferka> c_1 = std::unique_ptr<Cyferka>(new Cyferka(1));

    std::shared_ptr<Cyferka> c_2 = std::shared_ptr<Cyferka>(new Cyferka(2));
    std::shared_ptr<Cyferka> c_3 =
        c_2; // zwroc uwage, ze c_2 i c_3 wskazują na ten sam obiekt,
             // uzyj odpowiedniego smart pointera
    std::cout << "C1=" << *c_1 << " C2=" << *c_2 << " C3=" << *c_3 << std::endl;
    return 0;
}
