//
// Created by i32ropie on 27/03/18.
//

#ifndef RUBIK_EXTRA_HPP
#define RUBIK_EXTRA_HPP


#define TOP_LEFT_CORNER std::string("┌")
#define TOP_SEPARATOR std::string("┬")
#define TOP_RIGHT_CORNER std::string("┐")
#define DOWN_LEFT_CORNER std::string("└")
#define DOWN_SEPARATOR std::string("┴")
#define DOWN_RIGHT_CORNER std::string("┘")
#define HORIZONTAL_LINE std::string("──")
#define VERTICAL_LINE std::string("│")
#define MID_LEFT_SEPARATOR std::string("├")
#define MID_RIGHT_SEPARATOR std::string("┤")
#define FULL_SEPARATOR std::string("┼")

#define WHITE 1
#define YELLOW 2
#define RED 3
#define ORANGE 4
#define BLUE 5
#define GREEN 6

#define WHITE_BG "\e[48;2;255;255;255m  \e[0m"
#define YELLOW_BG "\e[48;2;255;255;0m  \e[0m"
#define RED_BG "\e[48;2;255;0;0m  \e[0m"
#define ORANGE_BG "\e[48;2;255;128;0m  \e[0m"
#define BLUE_BG "\e[48;2;0;0;255m  \e[0m"
#define GREEN_BG "\e[48;2;0;255;0m  \e[0m"

typedef int Color;

#include <map>

static std::map<Color, std::string> bg_color{
        {WHITE, WHITE_BG},
        {YELLOW, YELLOW_BG},
        {RED, RED_BG},
        {ORANGE, ORANGE_BG},
        {BLUE, BLUE_BG},
        {GREEN, GREEN_BG}
};

#endif //RUBIK_EXTRA_HPP
