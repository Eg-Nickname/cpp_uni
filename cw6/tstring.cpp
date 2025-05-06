#ifdef DEBUG
#include <iostream>
#endif

#include "tstring.hpp"

TString::TString(const char* s) : ptr{nullptr}, len{0} {
    if (s != nullptr) {
        len = strlen(s);
        ptr = new char[len + 1];
        strcpy(ptr, s);
    }
#ifdef DEBUG
    std::cout << "TString c‐tor " << len << " ‐ " << (ptr ? ptr : "pusty")
              << std::endl;
#endif
}

TString::TString(const TString& s) : ptr(nullptr), len(s.len) {
    if (len > 0) {
        ptr = new char[len + 1];
        strcpy(ptr, s.ptr);
    }
#ifdef DEBUG
    std::cout << "TString cc‐tor " << len << " ‐ " << (ptr ? ptr : "pusty")
              << std::endl;
#endif
}

TString& TString::operator=(const TString& s) {
    if (this != &s) {
        delete[] ptr;
        ptr = nullptr;
        len = s.len;
        if (len > 0) {
            ptr = new char[len + 1];
            strcpy(ptr, s.ptr);
        }
    }
#ifdef DEBUG
    std::cout << "TString copy operator= " << len << " ‐ "
              << (ptr ? ptr : "pusty") << std::endl;
#endif
    return *this;
}

TString::~TString() {
#ifdef DEBUG
    std::cout << "TString d‐tor " << len << " ‐ " << (ptr ? ptr : "pusty")
              << std::endl;
#endif
    delete[] ptr;
}