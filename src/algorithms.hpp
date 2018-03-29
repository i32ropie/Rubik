//
// Created by i32ropie on 28/03/18.
//

#ifndef RUBIK_ALGORITHMS_HPP
#define RUBIK_ALGORITHMS_HPP

#include "cube.hpp"

namespace edurolp{
    /// Map to parse the moves
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
        /**
         * @brief Execute a vector of moves over a cube
         * @param c Cube
         * @param moves Vector of moves
         */
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
                    default:
                        std::cout << "He recibido " << p << " en execute_moves." << std::endl;
                        exit(1);
                }
            }
        }
    public:
        // https://www.speedsolving.com/wiki/index.php/PLL
        class PLL{
        public:
            /// @name Permutations of edges only
            /**
             * @brief PLL H algorithm execution on a given cube
             * @param c Cube
             */
            const static void H(Cube &c){
                /// L R U2 L' R' F' B' U2 F B
                execute_moves(c, {"L", "R", "U", "U", "L'", "R'", "F'", "B'", "U", "U", "F", "B"});
            }
            /**
             * @brief PLL U1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void U1(Cube &c){
                /// R2 U' R' U' R U R U R U' R
                execute_moves(c, {"R", "R", "U'", "R'", "U'", "R", "U", "R", "U", "R", "U'", "R"});
            }
            /**
             * @brief PLL U2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void U2(Cube &c){
                /// R U' R U R U R' U' R' U' R' U2 R'
                execute_moves(c, {"R", "U'", "R", "U", "R", "U", "R'", "U'", "R'", "U'", "R'", "U", "U", "R'"});
            }
            /**
             * @brief PLL Z algorithm execution on a given cube
             * @param c Cube
             */
            const static void Z(Cube &c){
                /// U R' U' R U' R U R U' R' U R U R2 U' R' U
                execute_moves(c, {"U", "R'", "U'", "R", "U'", "R", "U", "R", "U'", "R'", "U", "R", "U", "R", "R", "U'", "R'", "U"});
            }
            /// @name Permutations of corners only
            /**
             * @brief PLL A1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void A1(Cube &c){
                /// R' F R' B2 R F' R' B2 R2
                execute_moves(c, {"R'", "F", "R'", "B", "B", "R", "F'", "R'", "B", "B", "R", "R"});
            }
            /**
             * @brief PLL A2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void A2(Cube &c){
                /// R B' R F2 R' B R F2 R2
                execute_moves(c, {"R", "B'", "R", "F", "F", "R'", "B", "R", "F", "F", "R", "R"});
            }
            /**
             * @brief PLL E algorithm execution on a given cube
             * @param c Cube
             */
            const static void E(Cube &c){
                /// D R' D2 F' D L D' F D2 R D' F' L' F
                execute_moves(c, {"D", "R'", "D", "D", "F'", "D", "L", "D'", "F", "D", "D", "R", "D'", "F'", "L'", "F"});
            }
            /// @name Permutations of corners and edges
            /**
             * @brief PLL F algorithm execution on a given cube
             * @param c Cube
             */
            const static void F(Cube &c){
                /// (R' U R U') R2 (F' U' F U) (R F R' F') R2 U'
                execute_moves(c, {"R'", "U", "R", "U'", "R", "R", "F'", "U'", "F", "U", "R", "F", "R'", "F'", "R", "R", "U'"});
            }
            /**
             * @brief PLL G1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void G1(Cube &c){
                /// (R U R' U' R') U F (R U R U' R') F' U R' U2 R
                execute_moves(c, {"R", "U", "R'", "U'", "R'", "U", "F", "R", "U", "R", "U'", "R'", "F'", "U", "R'", "U", "U", "R"});
            }
            /**
             * @brief PLL G2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void G2(Cube &c){
                /// R' U' R U D' R2 U R' U R U' R U' R2 D
                execute_moves(c, {"R'", "U'", "R", "U", "D'", "R", "R", "U", "R'", "U", "R", "U'", "R", "U'", "R", "R", "D"});
            }
            /**
             * @brief PLL G3 algorithm execution on a given cube
             * @param c Cube
             */
            const static void G3(Cube &c){
                /// L' U' L U L U' F' L' U' L' U L F U' L U2 L'
                execute_moves(c, {"L'", "U'", "L", "U", "L", "U'", "F'", "L'", "U'", "L'", "U", "L", "F", "U'", "L", "U", "U", "L'"});
            }
            /**
             * @brief PLL J1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void J1(Cube &c){
                /// (B' U F') U2 (B U' B') U2 (F B U')
                execute_moves(c, {"B'", "U", "F'", "U", "U", "B", "U'", "B'", "U", "U", "F", "B", "U'"});
            }
            /**
             * @brief PLL J2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void J2(Cube &c){
                /// R U2 (R' U' R) U2 L' (U R' U') L
                execute_moves(c, {"R", "U", "U", "R'", "U'", "R", "U", "U", "L'", "U", "R'", "U'", "L"});
            }
            /**
             * @brief PLL N1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void N1(Cube &c){
                /// (L U' R U2 L' U R')2 U'
                execute_moves(c, {"L", "U'", "R", "U", "U", "L'", "U", "R'", "L", "U'", "R", "U", "U", "L'", "U", "R'", "U'"});
            }
            /**
             * @brief PLL N2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void N2(Cube &c){
                /// (R' U L' U2 R U' L)2 U
                execute_moves(c, {"R'", "U", "L'", "U", "U", "R", "U'", "L", "R'", "U", "L'", "U", "U", "R", "U'", "L", "U"});
            }
            /**
             * @brief PLL R1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void R1(Cube &c){
                /// R U2 R' U2 R B' R' U' R U R B R2 U
                execute_moves(c, {"R", "U", "U", "R'", "U", "U", "R", "B'", "R'", "U'", "R", "U", "R", "B", "R", "R", "U"});
            }
            /**
             * @brief PLL R2 algorithm execution on a given cube
             * @param c Cube
             */
            const static void R2(Cube &c){
                /// R' U2 R U2 R' F (R U R' U') R' F' R2' U'
                execute_moves(c, {"R'", "U", "U", "R", "U", "U", "R'", "F", "R", "U", "R'", "U'", "R'", "F'", "R'", "R'", "U'"});
            }
            /**
             * @brief PLL T algorithm execution on a given cube
             * @param c Cube
             */
            const static void T(Cube &c){
                /// R U R' U' R' F R2 U' R' U' R U R' F'
                execute_moves(c, {"R", "U", "R'", "U'", "R'", "F", "R", "R", "U'", "R'", "U'", "R", "U", "R'", "F'"});
            }
            /**
             * @brief PLL V algorithm execution on a given cube
             * @param c Cube
             */
            const static void V(Cube &c){
                /// R' U R' U' B' R' B2 U' B' U B' R B R
                execute_moves(c, {"R'", "U", "R'", "U'", "B'", "R'", "B", "B", "U'", "B'", "U", "B'", "R", "B", "R"});
            }
            /**
             * @brief PLL Y algorithm execution on a given cube
             * @param c Cube
             */
            const static void Y(Cube &c){
                /// F R U' R' U' R U R' F' R U R' U' R' F R F'
                execute_moves(c, {"F", "R", "U'", "R'", "U'", "R", "U", "R'", "F'", "R", "U", "R'", "U'", "R'", "F", "R", "F'"});
            }
        };
        class OLL{
        public:
            /// @name All edges flipped correctly
            /**
             * @brief OLL 21 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _21(Cube &c){
                /// R U R' U R U' R' U R U2 R'
                execute_moves(c, {"R", "U", "R'", "U", "R", "U'", "R'", "U", "R", "U", "U", "R'"});
            }
            /**
             * @brief OLL 22 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _22(Cube &c){
                /// R' U L U' R U' L' U' L U' L'
                execute_moves(c, {"R'", "U", "L", "U'", "R", "U'", "L'", "U'", "L", "U'", "L'"});
            }
            /**
             * @brief OLL 23 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _23(Cube &c){
                /// R' U2 R F U' R' U' R U F'
                execute_moves(c, {"R'", "U", "U", "R", "F", "U'", "R'", "U'", "R", "U", "F'"});
            }
            /**
             * @brief OLL 24 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _24(Cube &c){
                /// L F R' F' L' F R F'
                execute_moves(c, {"L", "F", "R'", "F'", "L'", "F", "R", "F'"});
            }
            /**
             * @brief OLL 25 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _25(Cube &c){
                /// R2 D' R U' R' D R U R
                execute_moves(c, {"R", "R", "D'", "R", "U'", "R'", "D", "R", "U", "R"});
            }
            /**
             * @brief OLL 26 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _26(Cube &c){
                /// (R' U L U') (R U L')
                execute_moves(c, {"R'", "U", "L", "U'", "R", "U", "L'"});
            }
            /**
             * @brief OLL 27 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _27(Cube &c){
                /// R U' L' U R' U' L
                execute_moves(c, {"R", "U'", "L'", "U", "R'", "U'", "L"});
            }
            /// @name No edges flipped correctly
            /**
             * @brief OLL 1 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _1(Cube &c){
                /// R U B' R B R2 U' R' F R F'
                execute_moves(c, {"R", "U", "B'", "R", "B", "R", "R", "U'", "R'", "F", "R", "F'"});
            }
            /**
             * @brief OLL 17 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _17(Cube &c){
                /// R U R' U (R' F R F') U2 (R' F R F')
                execute_moves(c, {"R", "U", "R'", "U", "R'", "F", "R", "F'", "U", "U", "R'", "F", "R", "F'"});
            }
            /// @name "P" shapes
            /**
             * @brief OLL 31 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _31(Cube &c){
                /// L' U' B U L U' L' B' L
                execute_moves(c, {"L'", "U'", "B", "U", "L", "U'", "L'", "B'", "L"});
            }
            /**
             * @brief OLL 32 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _32(Cube &c){
                /// R U B' U' R' U R B R'
                execute_moves(c, {"R", "U", "B'", "U'", "R'", "U", "R", "B", "R'"});
            }
            /**
             * @brief OLL 43 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _43(Cube &c){
                /// B' U' R' U R B
                execute_moves(c, {"B'", "U'", "R'", "U", "R", "B"});
            }
            /// @name "W" shapes
            /**
             * @brief OLL 36 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _36(Cube &c){
                /// R' U' R U' R' U R U R B' R' B
                execute_moves(c, {"R'", "U'", "R", "U'", "R'", "U", "R", "U", "R", "B'", "R'", "B"});
            }
            /**
             * @brief OLL 38 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _38(Cube &c){
                /// L U L' U L U' L' U' L' B L B'
                execute_moves(c, {"L", "U", "L'", "U", "L", "U'", "L'", "U'", "L'", "B", "L", "B'"});
            }
            /// @name "L" shapes
            /**
             * @brief OLL 47 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _47(Cube &c){
                /// F' (L' U' L U) (L' U' L U) F
                execute_moves(c, {"F'", "L'", "U'", "L", "U", "L'", "U'", "L", "U", "F"});
            }
            /**
             * @brief OLL 48 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _48(Cube &c){
                /// F (R U R' U') (R U R' U') F'
                execute_moves(c, {"F", "R", "U", "R'", "U'", "R", "U", "R'", "U'", "F'"});
            }
            /**
             * @brief OLL 49 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _49(Cube &c){
                /// R B' R2 F R2 B R2 F' R
                execute_moves(c, {"R", "B'", "R", "R", "F", "R", "R", "B", "R", "R", "F'", "R"});
            }
            /**
             * @brief OLL 50 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _50(Cube &c){
                /// R B' R B R2' U2 F R' F' R
                execute_moves(c, {"R", "B'", "R", "B", "R'", "R'", "U", "U", "F", "R'", "F'", "R"});
            }
            /**
             * @brief OLL 53 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _53(Cube &c){
                /// F R U R' U' F' R U R' U' R' F R F'
                execute_moves(c, {"F", "R", "U", "R'", "U'", "F'", "R", "U", "R'", "U'", "R'", "F", "R", "F'"});
            }
            /// @name "C" shapes
            /**
             * @brief OLL 34 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _34(Cube &c){
                /// R U R2 U' R' F R U R U' F'
                execute_moves(c, {"R", "U", "R", "R", "U'", "R'", "F", "R", "U", "R", "U'", "F'"});
            }
            /**
             * @brief OLL 46 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _46(Cube &c){
                /// R' U' R' F R F' U R
                execute_moves(c, {"R'", "U'", "R'", "F", "R", "F'", "U", "R"});
            }
            /// @name "T" shapes
            /**
             * @brief OLL 33 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _33(Cube &c){
                /// (R U R' U') (R' F R F')
                execute_moves(c, {"R", "U", "R'", "U'", "R'", "F", "R", "F'"});
            }
            /**
             * @brief OLL 45 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _45(Cube &c){
                /// F (R U R' U') F'
                execute_moves(c, {"F", "R", "U", "R'", "U'", "F'"});
            }
            /// @name "I" shapes
            /**
             * @brief OLL 51 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _51(Cube &c){
                /// F U R U' R' U R U' R' F'
                execute_moves(c, {"F", "U", "R", "U'", "R'", "U", "R", "U'", "R'", "F'"});
            }
            /**
             * @brief OLL 52 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _52(Cube &c){
                /// R' U' R U' R' U F' U F R
                execute_moves(c, {"R'", "U'", "R", "U'", "R'", "U", "F'", "U", "F", "R"});
            }
            /**
             * @brief OLL 55 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _55(Cube &c){
                /// R U2 R2 U' R U' R' U2 F R F'
                execute_moves(c, {"R", "U", "U", "R", "R", "U'", "R", "U'", "R'", "U", "U", "F", "R", "F'"});
            }
            /**
             * @brief OLL 56 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _56(Cube &c){
                /// L F L' U R U' R' U R U' R' L F' L'
                execute_moves(c, {"L", "F", "L'", "U", "R", "U'", "R'", "U", "R", "U'", "R'", "L", "F'", "L'"});
            }
            /// @name Big lightning bolt shapes
            /**
             * @brief OLL 39 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _39(Cube &c){
                /// L F' (L' U' L U) F U' L'
                execute_moves(c, {"L", "F'", "L'", "U'", "L", "U", "F", "U'", "L'"});
            }
            /**
             * @brief OLL 40 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _40(Cube &c){
                /// R' F (R U R' U') F' U R
                execute_moves(c, {"R'", "F", "R", "U", "R'", "U'", "F'", "U", "R"});
            }
            /// @name Small lightning bolt shapes
            /**
             * @brief OLL 7 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _7(Cube &c){
                /// F R' F' R U2 R U2 R'
                execute_moves(c, {"F", "R'", "F'", "R", "U2", "R", "U", "U", "R'"});
            }
            /**
             * @brief OLL 8 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _8(Cube &c){
                /// R U2 R' U2 R' F R F'
                execute_moves(c, {"R", "U", "U", "R'", "U", "U", "R'", "F", "R", "F'"});
            }
            /**
             * @brief OLL 11 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _11(Cube &c){
                /// R U' R' U' R U' R' U2 F' U F U' R U R'
                execute_moves(c, {"R", "U'", "R'", "U'", "R", "U'", "R'", "U", "U", "F'", "U", "F", "U'", "R", "U", "R'"});
            }
            /**
             * @brief OLL 12 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _12(Cube &c){
                /// F (R U R' U') F' U F (R U R' U') F'
                execute_moves(c, {"F", "R", "U", "R'", "U'", "F'", "U", "F", "R", "U", "R'", "U'", "F'"});
            }
            /// @name Fish shapes
            /**
             * @brief OLL 9 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _9(Cube &c){
                /// R' U' R U' R' U R' F R F' U R
                execute_moves(c, {"R'", "U'", "R", "U'", "R'", "U", "R'", "F", "R", "F'", "U", "R"});
            }
            /**
             * @brief OLL 35 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _35(Cube &c){
                /// R U2 R2' F R F' R U2 R'
                execute_moves(c, {"R", "U", "U", "R", "R'", "F", "R", "F'", "R", "U", "U", "R'"});
            }
            /**
             * @brief OLL 37 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _37(Cube &c){
                /// R B' R' B U B U' B'
                execute_moves(c, {"R", "B'", "R'", "B", "U", "B", "U'", "B'"});
            }
            /// @name Knight move shapes
            /**
             * @brief OLL 13 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _13(Cube &c){
                /// F U R U2 R' U' R U R' F'
                execute_moves(c, {"F", "U", "R", "U", "U", "R'", "U'", "R", "U", "R'", "F'"});
            }
            /**
             * @brief OLL 14 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _14(Cube &c){
                /// F' U' L' U2 L U L' U' L F
                execute_moves(c, {"F'", "U'", "L'", "U", "U", "L", "U", "L'", "U'", "L", "F"});
            }
            /// @name Awkward shapes
            /**
             * @brief OLL 30 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _30(Cube &c){
                /// R2' U R' B' R U' R2' U R B R'
                execute_moves(c, {"R'", "R'", "U", "R'", "B'", "R", "U'", "R'", "R'", "U", "R", "B", "R'"});
            }
            /**
             * @brief OLL 42 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _42(Cube &c){
                /// R' U' R U F R U R' U' R' U R U' F'
                execute_moves(c, {"R'", "U'", "R", "U", "F", "R", "U", "R'", "U'", "R'", "U", "R", "U'", "F'"});
            }
            /// @name All Corners Oriented
            /**
             * @brief OLL 28 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _28(Cube &c){
                /// F R U R' U' F2 L' U' L U F
                execute_moves(c, {"F", "R", "U", "R'", "U'", "F", "F", "L'", "U'", "L", "U", "F"});
            }
            /**
             * @brief OLL 20 algorithm execution on a given cube
             * @param c Cube
             */
            const static void _20(Cube &c){
                /// L' R' F' U2 L2 U2 L2 U2 L2 F L R
                execute_moves(c, {"L'", "R'", "F'", "U", "U", "L", "L", "U", "U", "L", "L", "U", "U", "L", "L", "F", "L", "R"});
            }
        };
    };
}

#endif //RUBIK_ALGORITHMS_HPP
