//
// Created by i32ropie on 25/03/18.
//

#include <gtest/gtest.h>
#include "../src/colors.hpp"

TEST(Colors, colors_check){
    EXPECT_EQ(WHITE, 1);
    EXPECT_EQ(YELLOW, 2);
    EXPECT_EQ(RED, 3);
    EXPECT_EQ(ORANGE, 4);
    EXPECT_EQ(BLUE, 5);
    EXPECT_EQ(GREEN, 6);
}