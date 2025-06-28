#include<bits/stdc++.h>
#include "../rubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<class T> class IDDFSSolver {
    public:
        T rc;
        int max_depth;

        IDDFSSolver(T cube, int md = 8) : rc(cube), max_depth(md) {};

        vector<RubiksCube::MOVE> solve() {
            vector<RubiksCube::MOVE> moves;
            
            for (int depth = 0; depth <= max_depth; depth++) {
                if (iddfs(depth, moves)) {
                    return moves;
                }
            }
            
            return {};
        }

    private:
        bool iddfs(int depth, vector<RubiksCube::MOVE> &moves) {
            if (rc.isSolved()) {
                return true;
            }
            if (depth == 0) {
                return false;
            }

            for (int i = 0; i < 18; i++) {
                rc.move(RubiksCube::MOVE(i));
                moves.push_back(RubiksCube::MOVE(i));

                if (iddfs(depth - 1, moves)) {
                    return true;
                }

                moves.pop_back();
                rc.invert(RubiksCube::MOVE(i));
            }
            return false;
        }


};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H