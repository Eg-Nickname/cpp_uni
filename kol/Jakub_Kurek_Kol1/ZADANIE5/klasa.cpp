#include "klasa.h"
#include <cstring>

// Tu mozna napisac konieczne definicje
// Jesli potrzebne sa dodatkowe naglowki, mozna je dolaczyc tutaj.
Wyraz::Wyraz() {}
Wyraz::Wyraz(char* c) {
    ptr = new char[strlen(c) + 1];
    strcpy(ptr, c);
}
Wyraz::Wyraz(const Wyraz& c) {
    ptr = new char[strlen(c.ptr) + 1];
    strcpy(ptr, c.ptr);
}
Wyraz::~Wyraz() {
    if (ptr != nullptr) {
        delete ptr;
    }
}

void Wyraz::Print() {
    if (ptr != nullptr) {
        std::cout << ptr << std::endl;
    } else {
        std::cout << "BRAK WYRAZU" << std::endl;
    }

    return;
}
