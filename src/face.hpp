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
         * Constuctor for allowing being initialized with this {{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}}
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
    };

}

#endif //RUBIK_FACE_HPP
