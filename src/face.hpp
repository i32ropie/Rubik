//
// Created by i32ropie on 25/03/18.
//

#ifndef RUBIK_FACE_HPP
#define RUBIK_FACE_HPP

#include <vector>
#include <initializer_list>
#include "colors.hpp"

namespace edurolp{
    class Face{
    private:
        /// Variable with the face color info
        Color _c;
        /// Matrix with the data of the face
        std::vector< std::vector<Color> > _data;
        /// Variable to check if the face is solved or not
        bool _solved;
    public:
        /// @name Constructors
        /**
         * @brief Constructor given a matrix data
         * @param data Matrix data
         */
        Face(const std::vector< std::vector<Color> > &data): _data(data), _c(data.at(1).at(1)) {
            this->_solved = this->is_solved();
        }
        /**
         * @brief Constuctor for allowing being initialized with this {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}}
         * @param data Matrix data
         */
        Face(const std::initializer_list<std::initializer_list<Color> > &data) {
            for(const auto &element: data){
                _data.emplace_back(element);
            }
            this->_c = this->_data.at(1).at(1);
            this->_solved = this->is_solved();
        }
        /// @name Getters
        /**
         * @brief Get the face color
         * @return Color of the face
         */
        inline Color get_color() const { return this->_c; }
        /**
         * @brief Get the data matrix
         * @return Data matrix
         */
        inline std::vector<std::vector<Color>> get_data() const { return this->_data; }
        /**
         * @brief Check if the face is solved
         * @return True if face solved, False if not
         */
        bool is_solved() const {
            for(auto &i: this->get_data())
                for(auto &j: i)
                    if(j != this->get_color())
                        return false;
            return true;
        }
        std::vector<Color> get_top_layer() const {
            return this->_data[0];
        }
        std::vector<Color> get_down_layer() const {
            return this->_data[2];
        }
        std::vector<Color> get_right_layer() const {
            return std::vector<Color>{this->_data[0][2],
                                      this->_data[1][2],
                                      this->_data[2][2]};
        }
        std::vector<Color> get_left_layer() const {
            return std::vector<Color>{this->_data[0][0],
                                      this->_data[1][0],
                                      this->_data[2][0]};
        }
        /// @name Setters
        /**
         * @brief Swaps the top layer of the face
         * @param layer New top layer
         */
        void set_top_layer(const std::vector<Color> &layer) {
            this->_data[0] = layer;
        }
        /**
         * @brief Swaps the down layer of the face
         * @param layer New down layer
         */
        void set_down_layer(const std::vector<Color> &layer) {
            this->_data[2] = layer;
        }
        /**
         * @brief Swaps the right layer of the face
         * @param layer New right layer
         */
        void set_right_layer(const std::vector<Color> &layer) {
            for(int i = 0 ; i < 3 ; ++i)
                this->_data[i][2] = layer[i];
        }
        /**
         * @brief Swaps the left layer of the face
         * @param layer New left layer
         */
        void set_left_layer(const std::vector<Color> &layer) {
            for(int i = 0 ; i < 3 ; ++i)
                this->_data[i][0] = layer[i];
        }
        /// @name Modify functions
        /**
         * @brief Rotates the face clockwise
         */
        void rotate_clockwise() {
            std::vector<std::vector<Color>> tmp = this->get_data();
            ulong n = 3;
            for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < n ; ++j)
                    this->_data[j][n-i-1] = tmp[i][j];
        }
        /**
         * @brief Rotates the face anti clockwise
         */
        void rotate_anti_clockwise() {
            std::vector<std::vector<Color>> tmp = this->get_data();
            ulong n = 3;
            for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < n ; ++j)
                    this->_data[n-j-1][i] = tmp[i][j];
        }
    };

}

#endif //RUBIK_FACE_HPP
