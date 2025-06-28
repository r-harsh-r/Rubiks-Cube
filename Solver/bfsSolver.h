// dfs colver class for rubiks cube

#include<bits/stdc++.h>
#include "../rubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// T : type of rubiks cube
// H : hash function

template<typename T, typename H> 
class BFSSolver{
    public:
    T rc;
    int max_depth;
    unordered_map<T,RubiksCube::MOVE, H> move_map;
    unordered_map<T,bool, H> vis;

    BFSSolver(T cube,int md = 8)  : rc(cube) , max_depth(md) {};

    T bfs(T &cube){
        queue<T> q;
        vis[cube] = true;

        q.push(cube);

        while(!q.empty()){
            T node = q.front();
            q.pop();

            if(node.isSolved()){
                return node;
            }

            for(int i = 0;i<18;i++){
                T neigh = node;
                neigh.move(RubiksCube::MOVE(i));
                if(!vis[neigh]){
                    vis[neigh] = true;
                    move_map[neigh] = RubiksCube::MOVE(i);
                    q.push(neigh);
                }
            }
        }
    }

    vector<RubiksCube::MOVE> solve() {
        T solved = bfs(rc);
        vector<RubiksCube::MOVE> moves;

        while(!(solved == rc)){
            moves.push_back(move_map[solved]);
            solved.invert(move_map[solved]);
        }
        cout<<"hehe"<<endl;
        reverse(moves.begin(), moves.end());
        return moves;
    }

};


#endif