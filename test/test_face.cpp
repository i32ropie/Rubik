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

TEST(Face, rotation_simple){
    std::vector<std::vector<Color> > d1{{BLUE, WHITE, RED},
                                        {RED, RED, RED},
                                        {RED, RED, YELLOW}};
    std::vector<std::vector<Color> > d2{{RED, RED, BLUE},
                                        {RED, RED, WHITE},
                                        {YELLOW, RED, RED}};
    edurolp::Face f(d1);
    EXPECT_EQ(f.get_data(), d1);
    f.rotate_clockwise();
    EXPECT_EQ(f.get_data(), d2);
    f.rotate_anti_clockwise();
    EXPECT_EQ(f.get_data(), d1);
}

TEST(Face, rotation_multiple){
    std::vector<std::vector<Color> > d{{WHITE, WHITE, WHITE},
                                       {RED, RED, RED},
                                       {BLUE, BLUE, BLUE}};
    edurolp::Face f(d);
    for(int i = 0 ; i < 8000 ; ++i)
        f.rotate_clockwise();
    EXPECT_EQ(f.get_data(), d);
    for(int i = 0 ; i < 8000 ; ++i)
        f.rotate_anti_clockwise();
    EXPECT_EQ(f.get_data(), d);
}

TEST(Face, layers_swapping){
    std::vector<Color> layer{RED, RED, RED};
    std::vector<std::vector<Color> > d{{WHITE, WHITE, WHITE},
                                       {WHITE, WHITE, WHITE},
                                       {WHITE, WHITE, WHITE}};
    std::vector<std::vector<Color> > d1{{RED, RED, RED},
                                        {WHITE, WHITE, WHITE},
                                        {WHITE, WHITE, WHITE}};
    std::vector<std::vector<Color> > d2{{WHITE, WHITE, RED},
                                        {WHITE, WHITE, RED},
                                        {WHITE, WHITE, RED}};
    std::vector<std::vector<Color> > d3{{WHITE, WHITE, WHITE},
                                        {WHITE, WHITE, WHITE},
                                        {RED, RED, RED}};
    std::vector<std::vector<Color> > d4{{RED, WHITE, WHITE},
                                        {RED, WHITE, WHITE},
                                        {RED, WHITE, WHITE}};
    edurolp::Face f(d);
    f.set_top_layer(layer);
    EXPECT_EQ(f.get_data(), d1);
    f = d;
    f.set_right_layer(layer);
    EXPECT_EQ(f.get_data(), d2);
    f = d;
    f.set_down_layer(layer);
    EXPECT_EQ(f.get_data(), d3);
    f = d;
    f.set_left_layer(layer);
    EXPECT_EQ(f.get_data(), d4);

}