// dfs colver class for rubiks cube

#include<bits/stdc++.h>
#include "../rubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// T : type of rubiks cube
// H : hash function

template<typename T, typename H> 
class DFSSolver{
    public :
    T rc;
    private:
    int mov;
    int max_depth;
    int f;
    vector<RubiksCube::MOVE> moves;

    bool dfs(int dep){
        if(rc.isSolved()){
            return true;
        }

        if(dep >= max_depth){
            return false;
        }

        for(int i = 0;i<18;i++){
            rc.move(RubiksCube::MOVE(i));
            // cout<<"moving : "<<RubiksCube::getMove(RubiksCube::MOVE(i))<<endl;
            bool f = dfs(dep + 1);
            if(f){
                moves.push_back(RubiksCube::MOVE(i));
                return true;
            }
            // moves.pop_back();
            rc.invert(RubiksCube::MOVE(i));

            

        }

        return false;

    }

    public:

    DFSSolver(T cube, int max_depth = 8) : rc(cube), max_depth(max_depth) , mov(8) {};

    vector<RubiksCube::MOVE> solve() {
        f = dfs(0);

        return moves;
    }
    bool isSolved() const {
        return f;
    }
    
};


#endif