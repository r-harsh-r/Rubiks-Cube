#include<bits/stdc++.h>
#include "rubiksCube.h"
#include "rubiksCube3d.cpp"
#include "rubiksCubeArr.cpp"
#include "rubiksCubeBitBoard.cpp"
#include "./Solver/dfsSolver.h"
#include "./Solver/bfsSolver.h"
#include "./Solver/iddfsSolver.h"
using namespace std;

int main(){
    RubiksCube3dArray cube;
    cube.u();
    // cube.d();
    // cube.l();
    // cube.l();
    cube.print();

    
    
    // DFSSolver<RubiksCube3dArray,Hash3d> dfsSolver(cube);
    // vector<RubiksCube::MOVE> arr = dfsSolver.solve();
    // if(dfsSolver.isSolved()){
    //     cout<<"Solved in "<<arr.size()<<" moves"<<endl;
    //     reverse(arr.begin(), arr.end());
    //     for(auto x : arr){
    //         cout<<RubiksCube::getMove(x)<<" ";
    //     }
    // }else{
    //     cout<<"Not solved"<<endl;
    // }
       

    
    
    // BFSSolver<RubiksCube3dArray,Hash3d> bfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> arr = bfsSolver.solve();
    // for(auto x : arr){
    //     cout<<RubiksCube::getMove(x)<<" ";
    // }


    IDDFSSolver<RubiksCube3dArray> iddfsSolver(cube, 8);
    vector<RubiksCube::MOVE> arr = iddfsSolver.solve();
    for(auto x : arr){
        cout<<RubiksCube::getMove(x)<<" ";
    }

    cout<<endl;

}