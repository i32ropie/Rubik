//
// Created by i32ropie on 30/03/18.
//

#include <gtest/gtest.h>
#include "../src/solver.hpp"

TEST(Solver, check_centers){
    edurolp::Cube c1({{WHITE, WHITE, WHITE}, {WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c2;
    EXPECT_EQ(edurolp::Solver::check_centers(c1), false);
    EXPECT_EQ(edurolp::Solver::check_centers(c2), true);
    edurolp::Algorithms::scramble(c1);
    edurolp::Algorithms::scramble(c2);
    EXPECT_EQ(edurolp::Solver::check_centers(c1), false);
    EXPECT_EQ(edurolp::Solver::check_centers(c2), true);
}

TEST(Solver, check_colors){
    edurolp::Cube c1({{WHITE, WHITE, WHITE}, {WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c2;
    EXPECT_EQ(edurolp::Solver::check_colors(c1), false);
    EXPECT_EQ(edurolp::Solver::check_colors(c2), true);
    edurolp::Algorithms::scramble(c1);
    edurolp::Algorithms::scramble(c2);
    EXPECT_EQ(edurolp::Solver::check_colors(c1), false);
    EXPECT_EQ(edurolp::Solver::check_colors(c2), true);
}

TEST(Solver, check_edges){
    edurolp::Cube c1({{WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c2;
    EXPECT_EQ(edurolp::Solver::check_edges(c1), false);
    EXPECT_EQ(edurolp::Solver::check_edges(c2), true);
    edurolp::Algorithms::scramble(c1);
    edurolp::Algorithms::scramble(c2);
    EXPECT_EQ(edurolp::Solver::check_edges(c1), false);
    EXPECT_EQ(edurolp::Solver::check_edges(c2), true);
}

TEST(Solver, check_corners){
    edurolp::Cube c1({{RED, WHITE, WHITE}, {WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c2;
    EXPECT_EQ(edurolp::Solver::check_corners(c1), false);
    EXPECT_EQ(edurolp::Solver::check_corners(c2), true);
    edurolp::Algorithms::scramble(c1);
    edurolp::Algorithms::scramble(c2);
    EXPECT_EQ(edurolp::Solver::check_corners(c1), false);
    EXPECT_EQ(edurolp::Solver::check_corners(c2), true);
}

TEST(Solver, is_solvable){
    edurolp::Cube c1({{RED, RED, WHITE}, {WHITE, RED, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c2;
    EXPECT_EQ(edurolp::Solver::is_solvable(c1), false);
    EXPECT_EQ(edurolp::Solver::is_solvable(c2), true);
    edurolp::Algorithms::scramble(c1);
    edurolp::Algorithms::scramble(c2);
    EXPECT_EQ(edurolp::Solver::is_solvable(c1), false);
    EXPECT_EQ(edurolp::Solver::is_solvable(c2), true);
}

