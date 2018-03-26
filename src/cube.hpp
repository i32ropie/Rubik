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
        Face _down;
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
         * @param down Yellow face
         * @param back Orange face
         * @param left Green face
         * @param right Blue face
         */
        Cube(const Face &top, const Face &front, const Face &down, const Face &back, const Face &left, const Face &right):
                _top(top),
                _front(front),
                _down(down),
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
            _down({{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}}),
            _back({{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}}),
            _left({{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}}),
            _right({{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}}),
            _solved(this->is_solved()) {};
        /// @name Getters
        const Face &get_top() const {
            return _top;
        }

        const Face &get_front() const {
            return _front;
        }

        const Face &get_down() const {
            return _down;
        }

        const Face &get_back() const {
            return _back;
        }

        const Face &get_left() const {
            return _left;
        }

        const Face &get_right() const {
            return _right;
        }
        /**
         * @brief Check if the cube is solved by checking if every face is solved
         * @return True if the cube is solved, False if not
         */
        bool is_solved() const {
            for(auto &p: {_top, _front, _down, _back, _left, _right})
                if(!p.is_solved())
                    return false;
            return true;
        }
        /// @name Possible moves
        void R() {
            // Rotate face
            this->_right.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_right_layer();
            std::vector<Color> bk = this->_back.get_left_layer();
            std::vector<Color> dw = this->_down.get_right_layer();
            std::vector<Color> fr = this->_front.get_right_layer();
            this->_top.set_right_layer(fr);
            this->_back.set_left_layer(tp);
            this->_down.set_right_layer(bk);
            this->_front.set_right_layer(dw);
        }
        void R_prime() {
            // Rotate face
            this->_right.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_right_layer();
            std::vector<Color> bk = this->_back.get_left_layer();
            std::vector<Color> dw = this->_down.get_right_layer();
            std::vector<Color> fr = this->_front.get_right_layer();
            this->_top.set_right_layer(bk);
            this->_back.set_left_layer(dw);
            this->_down.set_right_layer(fr);
            this->_front.set_right_layer(tp);
        }
        void L() {
            // Rotate face
            this->_left.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_left_layer();
            std::vector<Color> bk = this->_back.get_right_layer();
            std::vector<Color> dw = this->_down.get_left_layer();
            std::vector<Color> fr = this->_front.get_left_layer();
            this->_top.set_left_layer(bk);
            this->_back.set_right_layer(dw);
            this->_down.set_left_layer(fr);
            this->_front.set_left_layer(tp);
        }
        void L_prime() {
            // Rotate face
            this->_left.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_left_layer();
            std::vector<Color> bk = this->_back.get_right_layer();
            std::vector<Color> dw = this->_down.get_left_layer();
            std::vector<Color> fr = this->_front.get_left_layer();
            this->_top.set_left_layer(fr);
            this->_back.set_right_layer(tp);
            this->_down.set_left_layer(bk);
            this->_front.set_left_layer(dw);
        }
        void U() {
            // Rotate face
            this->_top.rotate_clockwise();
            // Swap layers
            std::vector<Color> fr = this->_front.get_top_layer();
            std::vector<Color> rt = this->_right.get_top_layer();
            std::vector<Color> bk = this->_back.get_top_layer();
            std::vector<Color> lt = this->_left.get_top_layer();
            this->_front.set_top_layer(rt);
            this->_right.set_top_layer(bk);
            this->_back.set_top_layer(lt);
            this->_left.set_top_layer(fr);
        }
        void U_prime() {
            // Rotate face
            this->_top.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> fr = this->_front.get_top_layer();
            std::vector<Color> rt = this->_right.get_top_layer();
            std::vector<Color> bk = this->_back.get_top_layer();
            std::vector<Color> lt = this->_left.get_top_layer();
            this->_front.set_top_layer(lt);
            this->_right.set_top_layer(fr);
            this->_back.set_top_layer(rt);
            this->_left.set_top_layer(bk);
        }
        void D() {
            // Rotate face
            this->_down.rotate_clockwise();
            // Swap layers
            std::vector<Color> fr = this->_front.get_down_layer();
            std::vector<Color> rt = this->_right.get_down_layer();
            std::vector<Color> bk = this->_back.get_down_layer();
            std::vector<Color> lt = this->_left.get_down_layer();
            this->_front.set_down_layer(lt);
            this->_right.set_down_layer(fr);
            this->_back.set_down_layer(rt);
            this->_left.set_down_layer(bk);
        }
        void D_prime() {
            // Rotate face
            this->_down.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> fr = this->_front.get_down_layer();
            std::vector<Color> rt = this->_right.get_down_layer();
            std::vector<Color> bk = this->_back.get_down_layer();
            std::vector<Color> lt = this->_left.get_down_layer();
            this->_front.set_down_layer(rt);
            this->_right.set_down_layer(bk);
            this->_back.set_down_layer(lt);
            this->_left.set_down_layer(fr);
        }
        void F() {
            // Rotate face
            this->_front.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_down_layer();
            std::vector<Color> rt = this->_right.get_left_layer();
            std::vector<Color> dw = this->_down.get_top_layer();
            std::vector<Color> lt = this->_left.get_right_layer();
            this->_top.set_down_layer(lt);
            this->_right.set_left_layer(tp);
            this->_down.set_top_layer(rt);
            this->_left.set_right_layer(dw);
        }
        void F_prime() {
            // Rotate face
            this->_front.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_down_layer();
            std::vector<Color> rt = this->_right.get_left_layer();
            std::vector<Color> dw = this->_down.get_top_layer();
            std::vector<Color> lt = this->_left.get_right_layer();
            this->_top.set_down_layer(rt);
            this->_right.set_left_layer(dw);
            this->_down.set_top_layer(lt);
            this->_left.set_right_layer(tp);
        }
        void B() {
            // Rotate face
            this->_back.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_top_layer();
            std::vector<Color> rt = this->_right.get_right_layer();
            std::vector<Color> dw = this->_down.get_down_layer();
            std::vector<Color> lt = this->_left.get_left_layer();
            this->_top.set_top_layer(rt);
            this->_right.set_right_layer(dw);
            this->_down.set_down_layer(lt);
            this->_left.set_left_layer(tp);
        }
        void B_prime() {
            // Rotate face
            this->_back.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_top_layer();
            std::vector<Color> rt = this->_right.get_right_layer();
            std::vector<Color> dw = this->_down.get_down_layer();
            std::vector<Color> lt = this->_left.get_left_layer();
            this->_top.set_top_layer(lt);
            this->_right.set_right_layer(tp);
            this->_down.set_down_layer(rt);
            this->_left.set_left_layer(dw);
        }
    };
}

#endif //RUBIK_CUBE_HPP
