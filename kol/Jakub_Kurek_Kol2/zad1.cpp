///////////////////////
////// ZADANIE 1 //////
///////////////////////

// Mamy klase bazowa Rodzic, prosze ja uzupelnic o brakujaca rzecz.
// Prosze napisac tez klasy potomne, o nazwie Syn i Corka
// tak zeby dzialal program na koncu.

// Pamietej o zalaczeniu koniecznych naglowkow.
#include <iostream>
#include <string>

using std::string;

class Rodzic {
    protected:
    string nazwa;

    public:
    Rodzic(string n) : nazwa(n) {}
    virtual void mowi() = 0;

    // Czegos istotnego dla klasy bazowej tu jeszcze brakuje:
    virtual ~Rodzic() {}

    protected:
    string getNazwa() { return nazwa; }
};

// Napisz klasy dziedziczace publicznie z klasy bazowej Rodzic.
// Zdefiniuj w nuch konstruktor z jednym argumentem.
// Napisz metode skladowa mowi - wypisujaca na ekran
// zupelnie dowolny tekst ORAZ nazwe (za pomoca metody skladowej getNazwa())

class Syn : public Rodzic {
    public:
    Syn(string n) : Rodzic(n) {}
    virtual void mowi() {
        std::cout << "Jestem synem i nazywam sie " << this->getNazwa()
                  << std::endl;
    }
};

class Corka : public Rodzic {
    public:
    Corka(string n) : Rodzic(n) {}
    virtual void mowi() {
        std::cout << "Jestem córka i nazywam sie " << this->getNazwa()
                  << std::endl;
    }
};

// UWAGA: w ponizszym programie nalezy TYLKO uzupelnic brakujaca czesc na koncu
int main() {
    Rodzic *ptr1 = new Syn("Maly Jas");
    Rodzic *ptr2 = new Corka("Rezolutna Zosia");
    ptr1->mowi();
    ptr2->mowi();

    // Usuwamy wskaźniki
    delete ptr1;
    delete ptr2;

    return 0;
}
