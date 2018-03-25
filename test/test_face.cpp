//
// Created by i32ropie on 25/03/18.
//

#include <gtest/gtest.h>
#include "../src/face.hpp"

TEST(Face, face_unsolved){
    srand(time(NULL));
    std::vector<std::vector<Color> > data{
                                        {std::rand()%6 + 1, std::rand()%6 + 1, std::rand()%6 + 1},
                                        {std::rand()%6 + 1, 1, std::rand()%6 + 1},
                                        {std::rand()%6 + 1, std::rand()%6 + 1, std::rand()%6 + 1}};
    edurolp::Face f1(data);
    EXPECT_EQ(f1.get_color(), WHITE);
    EXPECT_EQ(f1.is_solved(), false);
    EXPECT_EQ(f1.get_data(), data);

    edurolp::Face f2({{BLUE, WHITE, RED},
                      {RED, RED, RED},
                      {RED, RED, YELLOW}});
    EXPECT_EQ(f2.get_color(), RED);
    EXPECT_EQ(f2.is_solved(), false);
}

TEST(Face, face_solved){
    std::vector<std::vector<Color> > data{
                                        {WHITE, WHITE, WHITE},
                                        {WHITE, WHITE, WHITE},
                                        {WHITE, WHITE, WHITE}};
    edurolp::Face f1(data);
    EXPECT_EQ(f1.get_color(), WHITE);
    EXPECT_EQ(f1.is_solved(), true);
    EXPECT_EQ(f1.get_data(), data);

    edurolp::Face f2({{RED, RED, RED},
                      {RED, RED, RED},
                      {RED, RED, RED}});
    EXPECT_EQ(f2.get_color(), RED);
    EXPECT_EQ(f2.is_solved(), true);
}
