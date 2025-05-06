#include "klasa.h"

// Tu piszemy definicje metod z klasy Litera
// Jesli potrzebne sa jakies dodatkowe naglowki, dolacz je tutaj.

Litera::Litera(char c) { lit = c; }
Litera::Litera(const Litera& c) { lit = c.lit; }
Litera& Litera::operator=(const Litera& c) {
    if (this != &c) {
        lit = c.lit;
    }
    return *this;
}
Litera::~Litera() {}