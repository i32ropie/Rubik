#include <iostream>
#include "algorithms.hpp"
#include "cube.hpp"

int main() {
    edurolp::Cube c;
    c.flip();
    edurolp::Algorithms::OLL::_20(c);
    std::cout << c << std::endl;
    return 0;
}