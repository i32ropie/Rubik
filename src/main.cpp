#include <iostream>
#include "solver.hpp"
#include "algorithms.hpp"
#include "cube.hpp"

int main() {
    edurolp::Cube c1({{WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Solver::solve(c1);
    return 0;
}