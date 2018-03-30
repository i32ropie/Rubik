//
// Created by i32ropie on 29/03/18.
//

#ifndef RUBIK_SOLVER_HPP
#define RUBIK_SOLVER_HPP

#include <algorithm>            // std::sort
#include <stdexcept>            // throw std::invalid_argument
#include "algorithms.hpp"

namespace edurolp{
    class Solver{
    public:
        /**
         * @brief Checks if the centers of a cube are ok
         * @param c Cube
         * @return True if the cube centers are ok
         */
        const static bool check_centers(const Cube &c){
            std::map<Color, Color> colors{
                    {WHITE, YELLOW},
                    {YELLOW, WHITE},
                    {RED, ORANGE},
                    {ORANGE, RED},
                    {BLUE, GREEN},
                    {GREEN, BLUE}
            };
            return c.get_down().get_color() == colors[c.get_top().get_color()] &&
                   c.get_back().get_color() == colors[c.get_front().get_color()] &&
                   c.get_left().get_color() == colors[c.get_right().get_color()];
        }
        /**
         * @brief Checks if the colors of a cube are ok
         * @param c Cube
         * @return True if the cube colors are ok
         */
        const static bool check_colors(const Cube &c){
            bool aux = true;
            std::map<Color, int> colors{
                    {WHITE, 0},
                    {YELLOW, 0},
                    {RED, 0},
                    {ORANGE, 0},
                    {BLUE, 0},
                    {GREEN, 0}
            };
            for(auto &p: c.get_all_faces())
                for(auto &x: p.get_data())
                    for(auto &y: x)
                        colors[y] += 1;
            for(auto &p: colors)
                if(p.second != 9)
                    aux = false;
            return aux;
        }
        /**
         * @brief Checks if the edges of a cube are ok
         * @param c Cube
         * @return True if the cube edges are ok
         */
        const static bool check_edges(const Cube &c){
            // 0 - _top, 1 - _down, 2 - _front, 3 - _back, 4 - _right, 5 - _left
            std::vector<Face> faces = c.get_all_faces();
            // Let's get all edges
            std::vector<std::vector<Color>> cube_edges{
                    // Top edges
                    {faces[0].get_data()[2][1], faces[2].get_data()[0][1]},
                    {faces[0].get_data()[0][1], faces[3].get_data()[0][1]},
                    {faces[0].get_data()[1][2], faces[4].get_data()[0][1]},
                    {faces[0].get_data()[1][0], faces[5].get_data()[0][1]},
                    // Down edges
                    {faces[1].get_data()[2][1], faces[3].get_data()[2][1]},
                    {faces[1].get_data()[0][1], faces[2].get_data()[2][1]},
                    {faces[1].get_data()[1][2], faces[4].get_data()[2][1]},
                    {faces[1].get_data()[1][0], faces[5].get_data()[2][1]},
                    // Middle edges
                    {faces[2].get_data()[1][2], faces[4].get_data()[1][0]},
                    {faces[2].get_data()[1][0], faces[5].get_data()[1][2]},
                    {faces[3].get_data()[1][2], faces[5].get_data()[1][0]},
                    {faces[3].get_data()[1][0], faces[4].get_data()[1][2]}
            };
            std::vector<std::vector<Color>> good_edges{
                    {WHITE, RED},
                    {WHITE, ORANGE},
                    {WHITE, BLUE},
                    {WHITE, GREEN},
                    {YELLOW, RED},
                    {YELLOW, ORANGE},
                    {YELLOW, BLUE},
                    {YELLOW, GREEN},
                    {RED, BLUE},
                    {RED, GREEN},
                    {ORANGE, BLUE},
                    {ORANGE, GREEN}
            };
            // Sort each edge so we can compare it with our good_edges variable
            for(auto &p: cube_edges)
                std::sort(p.begin(), p.end());
            // Now we sort them
            std::sort(cube_edges.begin(), cube_edges.end());
            // Return if our cube edges are the same of a good cube
            return cube_edges == good_edges;
        }
        /**
         * @brief Checks if the corners of a cube are ok
         * @param c Cube
         * @return True if the cube corners are ok
         */
        const static bool check_corners(const Cube &c){
            // 0 - _top, 1 - _down, 2 - _front, 3 - _back, 4 - _right, 5 - _left
            std::vector<Face> faces = c.get_all_faces();
            // Let's get all corners
            std::vector<std::vector<Color>> cube_corners{
                    // Top corners
                    {faces[0].get_data()[2][2], faces[2].get_data()[0][2], faces[4].get_data()[0][0]},
                    {faces[0].get_data()[2][0], faces[2].get_data()[0][0], faces[5].get_data()[0][2]},
                    {faces[0].get_data()[0][2], faces[3].get_data()[0][0], faces[4].get_data()[0][2]},
                    {faces[0].get_data()[0][0], faces[3].get_data()[0][2], faces[5].get_data()[0][0]},
                    // Down corners
                    {faces[1].get_data()[0][2], faces[2].get_data()[2][2], faces[4].get_data()[2][0]},
                    {faces[1].get_data()[0][0], faces[2].get_data()[2][0], faces[5].get_data()[2][2]},
                    {faces[1].get_data()[2][2], faces[3].get_data()[2][0], faces[4].get_data()[2][2]},
                    {faces[1].get_data()[2][0], faces[3].get_data()[2][2], faces[5].get_data()[2][0]}
            };
            std::vector<std::vector<Color>> good_corners{
                    {WHITE, RED, BLUE},
                    {WHITE, RED, GREEN},
                    {WHITE, ORANGE, BLUE},
                    {WHITE, ORANGE, GREEN},
                    {YELLOW, RED, BLUE},
                    {YELLOW, RED, GREEN},
                    {YELLOW, ORANGE, BLUE},
                    {YELLOW, ORANGE, GREEN}
            };
            // Sort the cube corners
            for(auto &p: cube_corners)
                std::sort(p.begin(), p.end());
            std::sort(cube_corners.begin(), cube_corners.end());
            // Check if cube corners are good corners
            return cube_corners == good_corners;
        };
        /**
         * @brief Checks if a cube is solvable or unsolvable
         * @param c Cube
         * @return Whether the cube is cube is solvable or unsolvable
         */
        const static bool is_solvable(const Cube &c){
            return check_centers(c) && check_colors(c) && check_edges(c) && check_corners(c);
        }
        /**
         * @brief Solves a given Cube
         * @param c Cube
         */
        const static void solve(Cube &c){
            if(not is_solvable(c)){
                throw std::logic_error("\e[1;31m[Error]\e[0m - \e[36mThe cube you are trying to solve is unsolvable\e[0m");
            }
        }
    };
}

#endif //RUBIK_SOLVER_HPP
