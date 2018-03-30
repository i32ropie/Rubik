//
// Created by i32ropie on 25/03/18.
//

#ifndef RUBIK_CUBE_HPP
#define RUBIK_CUBE_HPP

#include <vector>
#include "extra.hpp"
#include "face.hpp"

namespace edurolp{
    static std::string operator *(const std::string &s, size_t count){
        std::string ret;
        for(size_t i = 0 ; i < count ; ++i){
            ret += s;
        }
        return ret;
    }
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
        const std::vector<Face> get_all_faces() const {
            return std::vector<Face>{_top, _down, _front, _back, _right, _left};
        }
        /**
         * @brief Get top face of the cube
         * @return Top face
         */
        const Face &get_top() const {
            return _top;
        }
        /**
         * @brief Get front face of the cube
         * @return Front face
         */
        const Face &get_front() const {
            return _front;
        }
        /**
         * @brief Get down face of the cube
         * @return Down face
         */
        const Face &get_down() const {
            return _down;
        }
        /**
         * @brief Get back face of the cube
         * @return Back face
         */
        const Face &get_back() const {
            return _back;
        }
        /**
         * @brief Get left face of the cube
         * @return Left face
         */
        const Face &get_left() const {
            return _left;
        }
        /**
         * @brief Get right face of the cube
         * @return Right face
         */
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
        /**
         * @brief Apply R move on the cube
         */
        void R() {
            // Rotate face
            this->_right.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_right_layer(true);
            std::vector<Color> bk = this->_back.get_left_layer(true);
            std::vector<Color> dw = this->_down.get_right_layer();
            std::vector<Color> fr = this->_front.get_right_layer();
            this->_top.set_right_layer(fr);
            this->_back.set_left_layer(tp);
            this->_down.set_right_layer(bk);
            this->_front.set_right_layer(dw);
        }
        /**
         * @brief Apply R' move on the cube
         */
        void R_prime() {
            // Rotate face
            this->_right.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_right_layer();
            std::vector<Color> bk = this->_back.get_left_layer(true);
            std::vector<Color> dw = this->_down.get_right_layer(true);
            std::vector<Color> fr = this->_front.get_right_layer();
            this->_top.set_right_layer(bk);
            this->_back.set_left_layer(dw);
            this->_down.set_right_layer(fr);
            this->_front.set_right_layer(tp);
        }
        /**
         * @brief Apply L move on the cube
         */
        void L() {
            // Rotate face
            this->_left.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_left_layer();
            std::vector<Color> bk = this->_back.get_right_layer(true);
            std::vector<Color> dw = this->_down.get_left_layer(true);
            std::vector<Color> fr = this->_front.get_left_layer();
            this->_top.set_left_layer(bk);
            this->_back.set_right_layer(dw);
            this->_down.set_left_layer(fr);
            this->_front.set_left_layer(tp);
        }
        /**
         * @brief Apply L' move on the cube
         */
        void L_prime() {
            // Rotate face
            this->_left.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_left_layer(true);
            std::vector<Color> bk = this->_back.get_right_layer(true);
            std::vector<Color> dw = this->_down.get_left_layer();
            std::vector<Color> fr = this->_front.get_left_layer();
            this->_top.set_left_layer(fr);
            this->_back.set_right_layer(tp);
            this->_down.set_left_layer(bk);
            this->_front.set_left_layer(dw);
        }
        /**
         * @brief Apply U move on the cube
         */
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
        /**
         * @brief Apply U' move on the cube
         */
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
        /**
         * @brief Apply D move on the cube
         */
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
        /**
         * @brief Apply D' move on the cube
         */
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
        /**
         * @brief Apply F move on the cube
         */
        void F() {
            // Rotate face
            this->_front.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_down_layer();
            std::vector<Color> rt = this->_right.get_left_layer(true);
            std::vector<Color> dw = this->_down.get_top_layer();
            std::vector<Color> lt = this->_left.get_right_layer(true);
            this->_top.set_down_layer(lt);
            this->_right.set_left_layer(tp);
            this->_down.set_top_layer(rt);
            this->_left.set_right_layer(dw);
        }
        /**
         * @brief Apply F' move on the cube
         */
        void F_prime() {
            // Rotate face
            this->_front.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_down_layer(true);
            std::vector<Color> rt = this->_right.get_left_layer();
            std::vector<Color> dw = this->_down.get_top_layer(true);
            std::vector<Color> lt = this->_left.get_right_layer();
            this->_top.set_down_layer(rt);
            this->_right.set_left_layer(dw);
            this->_down.set_top_layer(lt);
            this->_left.set_right_layer(tp);
        }
        /**
         * @brief Apply B move on the cube
         */
        void B() {
            // Rotate face
            this->_back.rotate_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_top_layer(true);
            std::vector<Color> rt = this->_right.get_right_layer();
            std::vector<Color> dw = this->_down.get_down_layer(true);
            std::vector<Color> lt = this->_left.get_left_layer();
            this->_top.set_top_layer(rt);
            this->_right.set_right_layer(dw);
            this->_down.set_down_layer(lt);
            this->_left.set_left_layer(tp);
        }
        /**
         * @brief Apply B' move on the cube
         */
        void B_prime() {
            // Rotate face
            this->_back.rotate_anti_clockwise();
            // Swap layers
            std::vector<Color> tp = this->_top.get_top_layer();
            std::vector<Color> rt = this->_right.get_right_layer(true);
            std::vector<Color> dw = this->_down.get_down_layer();
            std::vector<Color> lt = this->_left.get_left_layer(true);
            this->_top.set_top_layer(lt);
            this->_right.set_right_layer(tp);
            this->_down.set_down_layer(rt);
            this->_left.set_left_layer(dw);
        }
        /**
         * @brief Function that flips the cube so OLL and PLL algorithms are easier for me to implement
         */
        void flip() {
            this->_top.rotate_clockwise();
            this->_top.rotate_clockwise();

            this->_down.rotate_clockwise();
            this->_down.rotate_clockwise();

            this->_front.rotate_clockwise();
            this->_front.rotate_clockwise();

            this->_back.rotate_clockwise();
            this->_back.rotate_clockwise();

            this->_right.rotate_clockwise();
            this->_right.rotate_clockwise();

            this->_left.rotate_clockwise();
            this->_left.rotate_clockwise();

            Face tmp = this->_right;
            this->_right = this->_left;
            this->_left = tmp;
            tmp = this->_top;
            this->_top = this->_down;
            this->_down = tmp;
        }
        /// @name Operator overloads
        /**
         * @brief Ostream overload to output the cube with colors
         * @param output Stream where the cube will be outputed
         * @param c Cube to output
         * @return Stream with the cube outputed in
         */
        friend std::ostream &operator <<(std::ostream &output, const Cube &c) {
            std::vector<std::vector<Color>> top   = c.get_top().get_data(),
                                            down  = c.get_down().get_data(),
                                            front = c.get_front().get_data(),
                                            back  = c.get_back().get_data(),
                                            right = c.get_right().get_data(),
                                            left  = c.get_left().get_data();

            output << "         " << TOP_LEFT_CORNER << (HORIZONTAL_LINE + TOP_SEPARATOR)*2 << HORIZONTAL_LINE << TOP_RIGHT_CORNER << std::endl;
            for(int i = 0 ; i < 3 ; ++i){
                output << "         " << VERTICAL_LINE << bg_color[top[i][0]] << VERTICAL_LINE <<  bg_color[top[i][1]] << VERTICAL_LINE << bg_color[top[i][2]] << VERTICAL_LINE << std::endl;
                if(i < 2)
                    output << "         " << MID_LEFT_SEPARATOR << (HORIZONTAL_LINE + FULL_SEPARATOR)*2 << HORIZONTAL_LINE << MID_RIGHT_SEPARATOR << std::endl;

            }
            output << TOP_LEFT_CORNER << (HORIZONTAL_LINE + TOP_SEPARATOR)*2 << HORIZONTAL_LINE << (FULL_SEPARATOR + HORIZONTAL_LINE)*4 << (TOP_SEPARATOR + HORIZONTAL_LINE)*5 << TOP_RIGHT_CORNER << std::endl;
            for(int i = 0 ; i < 3 ; ++i){
                for(auto &p: {left, front, right, back}){
                    for(int j = 0 ; j < 3 ; ++j){
                        output << VERTICAL_LINE << bg_color[p[i][j]];
                    }
                }
                output << VERTICAL_LINE << std::endl;
                if(i<2)
                    output << MID_LEFT_SEPARATOR << (HORIZONTAL_LINE + FULL_SEPARATOR)*11 << HORIZONTAL_LINE << MID_RIGHT_SEPARATOR << std::endl;
                else
                    output << DOWN_LEFT_CORNER << (HORIZONTAL_LINE + DOWN_SEPARATOR)*2 << (HORIZONTAL_LINE + FULL_SEPARATOR)*4 << (HORIZONTAL_LINE + DOWN_SEPARATOR)*5 << HORIZONTAL_LINE << DOWN_RIGHT_CORNER << std::endl;
            }
            for(int i = 0 ; i < 3 ; ++i){
                output << "         " << VERTICAL_LINE << bg_color[down[i][0]] << VERTICAL_LINE <<  bg_color[down[i][1]] << VERTICAL_LINE << bg_color[down[i][2]] << VERTICAL_LINE << std::endl;
                if(i < 2)
                    output << "         " << MID_LEFT_SEPARATOR << (HORIZONTAL_LINE + FULL_SEPARATOR)*2 << HORIZONTAL_LINE << MID_RIGHT_SEPARATOR << std::endl;

            }
            output << "         " << DOWN_LEFT_CORNER << (HORIZONTAL_LINE + DOWN_SEPARATOR)*2 << HORIZONTAL_LINE << DOWN_RIGHT_CORNER << std::endl;
            return output;
        }
    };
}

#endif //RUBIK_CUBE_HPP
