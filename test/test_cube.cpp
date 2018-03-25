//
// Created by i32ropie on 26/03/18.
//

#include <gtest/gtest.h>
#include "../src/face.hpp"
#include "../src/cube.hpp"

TEST(Cube, cube_unsolved){
    edurolp::Face   top({{RED, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}}),
                    front({{WHITE, RED, RED}, {RED, RED, RED}, {RED, RED, RED}}),
                    bot({{RED, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}}),
                    back({{RED, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}}),
                    left({{RED, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}}),
                    right({{RED, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});

    edurolp::Cube c1(top, front, bot, back, left, right);
    edurolp::Cube c2({{RED, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}},
                     {{WHITE, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{RED, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{RED, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{RED, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{RED, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    EXPECT_EQ(c1.is_solved(), false);
    EXPECT_EQ(c2.is_solved(), false);

}

TEST(Cube, cube_solved){
    edurolp::Face   top({{WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}}),
                    front({{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}}),
                    bot({{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}}),
                    back({{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}}),
                    left({{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}}),
                    right({{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});

    edurolp::Cube c1(top, front, bot, back, left, right);
    edurolp::Cube c2({{WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}},
                     {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
                     {{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
                     {{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
                     {{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}},
                     {{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}});
    edurolp::Cube c3;
    EXPECT_EQ(c1.is_solved(), true);
    EXPECT_EQ(c2.is_solved(), true);
    EXPECT_EQ(c3.is_solved(), true);
}