#ifndef TSTRING_HPP
#define TSTRING_HPP

#include <cstring>

class TString {
    private:
    char* ptr = nullptr;
    std::size_t len = 0;

    public:
    TString(const char* s = nullptr);
    TString(const TString& s);
    TString& operator=(const TString& s);
    ~TString();
};

#endif