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
        class PLL{
        public:
            /// @name Permutations of edges only
            const static void H(Cube &c){
                // L R U2 L' R' F' B' U2 F B
                execute_moves(c, {"L", "R", "U", "U", "L'", "R'", "F'", "B'", "U", "U", "F", "B"});
            }
            const static void U1(Cube &c){
                // R2 U' R' U' R U R U R U' R
                execute_moves(c, {"R", "R", "U'", "R'", "U'", "R", "U", "R", "U", "R", "U'", "R"});
            }
            const static void U2(Cube &c){
                // R U' R U R U R' U' R' U' R' U2 R'
                execute_moves(c, {"R", "U'", "R", "U", "R", "U", "R'", "U'", "R'", "U'", "R'", "U", "U", "R'"});
            }
            const static void Z(Cube &c){
                // U R' U' R U' R U R U' R' U R U R2 U' R' U
                execute_moves(c, {"U", "R'", "U'", "R", "U'", "R", "U", "R", "U'", "R'", "U", "R", "U", "R", "R", "U'", "R'", "U"});
            }
            /// @name Permutations of corners only
            const static void A1(Cube &c){
                // R' F R' B2 R F' R' B2 R2
                execute_moves(c, {"R'", "F", "R'", "B", "B", "R", "F'", "R'", "B", "B", "R", "R"});
            }
            const static void A2(Cube &c){
                // R B' R F2 R' B R F2 R2
                execute_moves(c, {"R", "B'", "R", "F", "F", "R'", "B", "R", "F", "F", "R", "R"});
            }
            const static void E(Cube &c){
                // D R' D2 F' D L D' F D2 R D' F' L' F
                execute_moves(c, {"D", "R'", "D", "D", "F'", "D", "L", "D'", "F", "D", "D", "R", "D'", "F'", "L'", "F"});
            }
            /// @name Permutations of corners and edges
            const static void F(Cube &c){
                // (R' U R U') R2 (F' U' F U) (R F R' F') R2 U'
                execute_moves(c, {"R'", "U", "R", "U'", "R", "R", "F'", "U'", "F", "U", "R", "F", "R'", "F'", "R", "R", "U'"});
            }
            const static void G1(Cube &c){
                // (R U R' U' R') U F (R U R U' R') F' U R' U2 R
                execute_moves(c, {"R", "U", "R'", "U'", "R'", "U", "F", "R", "U", "R", "U'", "R'", "F'", "U", "R'", "U", "U", "R"});
            }
            const static void G2(Cube &c){
                // R' U' R U D' R2 U R' U R U' R U' R2 D
                execute_moves(c, {"R'", "U'", "R", "U", "D'", "R", "R", "U", "R'", "U", "R", "U'", "R", "U'", "R", "R", "D"});
            }
            const static void G3(Cube &c){
                // L' U' L U L U' F' L' U' L' U L F U' L U2 L'
                execute_moves(c, {"L'", "U'", "L", "U", "L", "U'", "F'", "L'", "U'", "L'", "U", "L", "F", "U'", "L", "U", "U", "L'"});
            }
            const static void J1(Cube &c){
                // (B' U F') U2 (B U' B') U2 (F B U')
                execute_moves(c, {"B'", "U", "F'", "U", "U", "B", "U'", "B'", "U", "U", "F", "B", "U'"});
            }
            const static void J2(Cube &c){
                // R U2 (R' U' R) U2 L' (U R' U') L
                execute_moves(c, {"R", "U", "U", "R'", "U'", "R", "U", "U", "L'", "U", "R'", "U'", "L"});
            }
            const static void N1(Cube &c){
                // (L U' R U2 L' U R')2 U'
                execute_moves(c, {"L", "U'", "R", "U", "U", "L'", "U", "R'", "L", "U'", "R", "U", "U", "L'", "U", "R'", "U'"});
            }
            const static void N2(Cube &c){
                // (R' U L' U2 R U' L)2 U
                execute_moves(c, {"R'", "U", "L'", "U", "U", "R", "U'", "L", "R'", "U", "L'", "U", "U", "R", "U'", "L", "U"});
            }
            const static void R1(Cube &c){
                // R U2 R' U2 R B' R' U' R U R B R2 U
                execute_moves(c, {"R", "U", "U", "R'", "U", "U", "R", "B'", "R'", "U'", "R", "U", "R", "B", "R", "R", "U"});
            }
            const static void R2(Cube &c){
                // R' U2 R U2 R' F (R U R' U') R' F' R2' U'
                execute_moves(c, {"R'", "U", "U", "R", "U", "U", "R'", "F", "R", "U", "R'", "U'", "R'", "F'", "R'", "R'", "U'"});
            }
            const static void T(Cube &c){
                // R U R' U' R' F R2 U' R' U' R U R' F'
                execute_moves(c, {"R", "U", "R'", "U'", "R'", "F", "R", "R", "U'", "R'", "U'", "R", "U", "R'", "F'"});
            }
            const static void V(Cube &c){
                // R' U R' U' B' R' B2 U' B' U B' R B R
                execute_moves(c, {"R'", "U", "R'", "U'", "B'", "R'", "B", "B", "U'", "B'", "U", "B'", "R", "B", "R"});
            }
            const static void Y(Cube &c){
                // F R U' R' U' R U R' F' R U R' U' R' F R F'
                execute_moves(c, {"F", "R", "U'", "R'", "U'", "R", "U", "R'", "F'", "R", "U", "R'", "U'", "R'", "F", "R", "F'"});
            }
        };
    };
}

#endif //RUBIK_ALGORITHMS_HPP
