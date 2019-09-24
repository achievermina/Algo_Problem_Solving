//
//  Leet463_islandPerimeter.cpp
//  algo
//
//  Created by Mina on 19/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>

//똑같은 코드인데 helper함수를 쓸 떄와 안쓸 떄의 속도차이가 엄청나다.. 왜지?


int islandPerimeter(vector<vector<int>>& grid) {
    int count=0;
    stack<int> st;
    
    if(grid.size()<1)
        return 0;
    
    for(int i =0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j]==1){
                count+= (i==0 ||grid[i-1][j]==0? 1:0);
                count+= (j==0 ||grid[i][j-1]==0? 1:0);
                count+= (i==grid.size()-1||grid[i+1][j]==0? 1:0);
                count+=(j==grid[0].size()-1 ||grid[i][j+1]==0? 1:0);
            }
            
        }
    }
    
    return count;
}


//VERY SLOW

//int islandPerimeter(vector<vector<int>>& grid) {
//    int count=0;
//    stack<int> st;
//
//    if(grid.size()<1)
//        return 0;
//
//    for(int i =0; i<grid.size(); i++){
//        for(int j=0; j<grid[0].size(); j++){
//            if(grid[i][j]==1){
//                count +=checkSides(grid, i, j);
//            }
//
//        }
//    }
//
//    return count;
//}
//
//int checkSides(vector<vector<int>>& grid, int i, int j){
//    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
//    int side=0;
//
//    for(int k=0; k<dir.size(); k++){
//        int i2 =i+dir[k][0];
//        int j2 =j+dir[k][1];
//
//        if(i2>=grid.size() || j2>=grid[0].size() || i2<0 || j2<0)
//            side++;
//        else if(grid[i2][j2]==0){
//            side++;
//        }
//    }
//    return side;
//
//    }
