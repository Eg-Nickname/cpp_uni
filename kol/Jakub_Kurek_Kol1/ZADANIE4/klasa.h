#ifndef LITERKA
#define LITERKA

#include <iostream>

// To jest definicja klasy oraz deklaracje, ktorych
// definicje nalezy umiescic w pliku klasa.cpp
// W tym pliku dopisz header guards.

class Litera {
    public:
    Litera(char c);
    Litera(const Litera& c);
    Litera& operator=(const Litera& c);
    ~Litera();

    char print() const { return lit; }

    private:
    char lit;
};

#endif
