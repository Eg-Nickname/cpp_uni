#include "complex.hpp"
#include <cmath>
Complex::Complex() : real(0.0), imaginary(1.0) {};
Complex::Complex(long double re, long double im) {
    this->real = re;
    this->imaginary = im;
};
Complex::Complex(const Complex &c) {
    this->real = c.real;
    this->imaginary = c.imaginary;
};
Complex &Complex::operator=(const Complex &c) {
    if (this != &c) {
        this->real = c.real;
        this->imaginary = c.imaginary;
    }
    return *this;
};
Complex Complex::operator+(const Complex &c) const {
    return Complex(this->real + c.real, this->imaginary + c.imaginary);
};
Complex Complex::operator-(const Complex &c) const {
    return Complex(this->real - c.real, this->imaginary - c.imaginary);
};
Complex Complex::operator!() const {
    return Complex(this->real, -this->imaginary);
}
long double Complex::operator~() const {
    return std::sqrt(this->real * this->real +
                     this->imaginary * this->imaginary);
};
std::ostream &operator<<(std::ostream &str, const Complex &c) {
    if (c.imaginary >= 0) {
        return str << c.real << "+" << c.imaginary << "i";
    } else {
        return str << c.real << c.imaginary << "i";
    }
};