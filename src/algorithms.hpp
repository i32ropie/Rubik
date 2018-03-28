//
// Created by i32ropie on 28/03/18.
//

#ifndef RUBIK_ALGORITHMS_HPP
#define RUBIK_ALGORITHMS_HPP

#include "cube.hpp"

namespace edurolp{
    static std::map<std::string, int> moves_to_int{
            {"R" , 1},
            {"R'", 2},
            {"L" , 3},
            {"L'", 4},
            {"U" , 5},
            {"U'", 6},
            {"D" , 7},
            {"D'", 8},
            {"F" , 9},
            {"F'", 10},
            {"B" , 11},
            {"B'", 12}
    };
    class Algorithms{
    private:
        Algorithms(){}
        const static void execute_moves(Cube &c, const std::vector<std::string> &moves){
            for(auto &p: moves){
                switch (moves_to_int[p]){
                    case 1:
                        c.R();       break;
                    case 2:
                        c.R_prime(); break;
                    case 3:
                        c.L();       break;
                    case 4:
                        c.L_prime(); break;
                    case 5:
                        c.U();       break;
                    case 6:
                        c.U_prime(); break;
                    case 7:
                        c.D();       break;
                    case 8:
                        c.D_prime(); break;
                    case 9:
                        c.F();       break;
                    case 10:
                        c.F_prime(); break;
                    case 11:
                        c.B();       break;
                    case 12:
                        c.B_prime(); break;
                }
            }
        }
    public:
        // https://www.speedsolving.com/wiki/index.php/PLL
        const static void PLL_T(Cube &c) {
            // [R U R' U'] R' F R2 U' R' U' [R U R' F']
            execute_moves(c, {"R", "U", "R'", "U'", "R'", "F", "R", "R", "U'", "R'", "U'", "R", "U", "R'", "F'"});
        }
        const static void PLL_H(Cube &c){
            // L R U2 L' R' F' B' U2 F B
            execute_moves(c, {"L", "R", "U", "U", "L'", "R'", "F'", "B'", "U", "U", "F", "B"});
        }
        const static void PLL_U(Cube &c){
            // R2 U' R' U' R U R U R U' R
            execute_moves(c, {"R", "R", "U'", "R'", "U'", "R", "U", "R", "U", "R", "U'", "R"});
        }
    };
}

#endif //RUBIK_ALGORITHMS_HPP
