#include "complex.hpp"
#include <iostream>

auto main(int argc, char** argv) -> int {
    Complex c1(1.0, 1.0);
    Complex c2(2.0, 2.0);
    Complex c3 = !c1;
    long double c4 = ~c2;
    Complex c5 = c1 - c2;
    Complex c6 = c1 + c2;
    std::cout << "c1=" << c1 << " c2=" << c2 << " c3=" << c3 << " c4=" << c4
              << " c5=" << c5 << " c6" << c6 << std::endl;
    Complex c7 = c6;
    c6 = c5;
    std::cout << "coping constructor c7=" << c7 << " from c6 and "
              << " c6 reasigned to c5 =" << c6 << std::endl;
    return 0;
}
