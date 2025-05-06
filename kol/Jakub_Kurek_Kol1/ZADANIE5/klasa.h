#ifndef WYRAZ
#define WYRAZ
#include <cstring>
#include <iostream>

// To jest definicja klasy. Prosze napisac konieczne deklaracje.
// Definicje prosze umiescic w pliku klasa.cpp
// Prosze dopisac header guards

class Wyraz {
    public:
    // Prosze napisac deklaracje koniecznego konstruktora/konstruktorow,
    // destruktora. UWAGA - zmienna ptr powinna być zaalokowana dynamicznie,
    // za pomocą operatora new, tak jak w przykładzie z zajęć z klasą TString
    Wyraz();
    Wyraz(char* c);
    Wyraz(const Wyraz& c);
    ~Wyraz();
    void Print();

    private:
    char* ptr = nullptr;
};

#endif