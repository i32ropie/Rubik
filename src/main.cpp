#include <iostream>
#include "algorithms.hpp"
#include "cube.hpp"

int main() {
    edurolp::Cube c;
    std::string scram = edurolp::Algorithms::scramble(c);
    std::cout << c << std::endl;
    std::cout << scram << std::endl;
    return 0;
}