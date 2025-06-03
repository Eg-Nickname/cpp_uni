#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <ostream>
class Complex {
    private:
    long double real;
    long double imaginary;
    friend std::ostream &operator<<(std::ostream &str, const Complex &c);

    public:
    Complex();
    Complex(long double re, long double im);
    Complex(const Complex &);
    Complex &operator=(const Complex &);
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator!() const;
    long double operator~() const;
};
#endif