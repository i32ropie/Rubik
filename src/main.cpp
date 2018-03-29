#include <iostream>
#include "algorithms.hpp"
#include "cube.hpp"

int main() {
    edurolp::Cube c;
    c.flip();
    edurolp::Algorithms::PLL::T(c);
    std::cout << c << std::endl;
    return 0;
}