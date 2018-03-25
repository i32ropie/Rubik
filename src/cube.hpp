//
// Created by i32ropie on 25/03/18.
//

#ifndef RUBIK_CUBE_HPP
#define RUBIK_CUBE_HPP

#include <vector>
#include "face.hpp"

namespace edurolp{
    class Cube{
    private:
        /// White face
        Face _top;
        /// Red face
        Face _front;
        /// Yellow face
        Face _bot;
        /// Orange face
        Face _back;
        /// Green face
        Face _left;
        /// Blue face
        Face _right;
        /// Variable to check if the cube is solved or not
        bool _solved;
    public:
        /// @name Constructors
        /**
         * @brief Constructor given Face objects
         * @param top White face
         * @param front Red face
         * @param bot Yellow face
         * @param back Orange face
         * @param left Green face
         * @param right Blue face
         */
        Cube(const Face &top, const Face &front, const Face &bot, const Face &back, const Face &left, const Face &right):
                _top(top),
                _front(front),
                _bot(bot),
                _back(back),
                _left(left),
                _right(right),
                _solved(this->is_solved()) {};
        /**
         * @brief Constructor that generates a solved cube. Used for testing purposes
         */
        Cube():
            _top({{WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}}),
            _front({{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}}),
            _bot({{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}}),
            _back({{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}}),
            _left({{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}}),
            _right({{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}}),
            _solved(this->is_solved()) {};
        /// @name Getters
        /**
         * @brief Check if the cube is solved by checking if every face is solved
         * @return True if the cube is solved, False if not
         */
        bool is_solved() const {
            for(auto &p: {_top, _front, _bot, _back, _left, _right})
                if(!p.is_solved())
                    return false;
            return true;
        }

    };
}

#endif //RUBIK_CUBE_HPP
