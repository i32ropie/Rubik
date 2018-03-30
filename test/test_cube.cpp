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

TEST(Cube, moveset_r){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.R();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_r_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.R_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_right().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_top().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_back().get_left_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_down().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_front().get_right_layer(), tmp);
                break;
        }
    }
    c.R_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_l){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.L();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_l_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.L_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_left().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_top().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_back().get_right_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_down().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_front().get_left_layer(), tmp);
                break;
        }
    }
    c.L_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_u){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.U();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, BLUE, ORANGE, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_u_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.U_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, BLUE, ORANGE, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_left().get_top_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_front().get_top_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_right().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_back().get_top_layer(), tmp);
                break;
        }
    }
    c.U_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_d){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.D();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_down().is_solved(), true);
    for(auto &p: {RED, BLUE, ORANGE, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_down().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_down().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_d_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.D_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, BLUE, ORANGE, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case RED:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case ORANGE:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_top().is_solved(), true);
    for(auto &p: {RED, WHITE, ORANGE, YELLOW}) {
        tmp = {p, p, p};
        switch (p){
            case ORANGE:
                EXPECT_EQ(c.get_left().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_front().get_down_layer(), tmp);
                break;
            case RED:
                EXPECT_EQ(c.get_right().get_down_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_back().get_down_layer(), tmp);
                break;
        }
    }
    c.D_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_f){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.F();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case WHITE:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_f_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.F_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case WHITE:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_front().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_left().get_right_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_top().get_down_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_right().get_left_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_down().get_top_layer(), tmp);
                break;
        }
    }
    c.F_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_b){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.B();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case WHITE:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, moveset_b_prime){
    std::vector<Color> tmp;
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    c.B_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case YELLOW:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case BLUE:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case WHITE:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B_prime();
    EXPECT_EQ(c.is_solved(), false);
    EXPECT_EQ(c.get_back().is_solved(), true);
    for(auto &p: {WHITE, BLUE, YELLOW, GREEN}) {
        tmp = {p, p, p};
        switch (p){
            case WHITE:
                EXPECT_EQ(c.get_left().get_left_layer(), tmp);
                break;
            case BLUE:
                EXPECT_EQ(c.get_top().get_top_layer(), tmp);
                break;
            case YELLOW:
                EXPECT_EQ(c.get_right().get_right_layer(), tmp);
                break;
            case GREEN:
                EXPECT_EQ(c.get_down().get_down_layer(), tmp);
                break;
        }
    }
    c.B_prime();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, flip){
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    // R move and flip it and expect to have yellow face on top with left layer changed to orange
    c.R();
    c.flip();
    edurolp::Face f1{{ORANGE, YELLOW, YELLOW},
                     {ORANGE, YELLOW, YELLOW},
                     {ORANGE, YELLOW, YELLOW}};
    edurolp::Face f2{{YELLOW, RED, RED},
                     {YELLOW, RED, RED},
                     {YELLOW, RED, RED}};
    edurolp::Face f3{{RED, WHITE, WHITE},
                     {RED, WHITE, WHITE},
                     {RED, WHITE, WHITE}};
    edurolp::Face f4{{ORANGE, ORANGE, WHITE},
                     {ORANGE, ORANGE, WHITE},
                     {ORANGE, ORANGE, WHITE}};
    EXPECT_EQ(c.get_top().get_data(), f1.get_data());
    EXPECT_EQ(c.get_front().get_data(), f2.get_data());
    EXPECT_EQ(c.get_down().get_data(), f3.get_data());
    EXPECT_EQ(c.get_back().get_data(), f4.get_data());
    // L' move and flip it and expect to have the cube solved
    c.L_prime();
    c.flip();
    EXPECT_EQ(c.is_solved(), true);
}

TEST(Cube, small_algorithm){
    edurolp::Cube c;
    EXPECT_EQ(c.is_solved(), true);
    for(int i = 0 ; i < 6 ; ++i){
        c.R();
        c.U();
        c.R_prime();
        c.U_prime();
    }
    EXPECT_EQ(c.is_solved(), true);
}