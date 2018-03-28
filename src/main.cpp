#include <iostream>
#include "algorithms.hpp"
#include "cube.hpp"

int main() {
    edurolp::Cube c;
    std::cout << c << std::endl;
    edurolp::Algorithms::PLL_U(c);
    std::cout << c << std::endl;
    return 0;
}