#include "tstring.hpp"

auto main() -> int {
    TString s1;
    TString s2 = TString("Inicjalizacja slowem");
    TString s3 = TString(s2);
    TString s4;
    s4 = s2;
    TString *s5 = new TString("Bla bla bla");
    delete s5;
    return 0;
}