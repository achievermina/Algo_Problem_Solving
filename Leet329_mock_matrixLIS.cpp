//
//  Leet329_mock_matrixLIS.cpp
//  algo
//
//  Created by Mina on 11/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
/*
 
 Given an integer matrix, find the length of the longest increasing path.
 
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 
 Example 1:
 
 Input: nums =
 [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
 Output: 4
 Explanation: The longest increasing path is [1, 2, 6, 9].
 Example 2:
 
 Input: nums =
 [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
 Output: 4
 Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 
 */
//REFERENCE: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/351687/The-way-to-come-up-with-the-dp-solution-of-6ms

//DFS +DP

bool check(int i, int j ,int rowSize, int colSize){
    if(i<0 || i>rowSize-1 || j<0 || j>colSize-1)
        return false;
    else
        return true;
}

int DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> dp){
    int dpMax=0;
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    int current = matrix[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    //left
    if(check(i,j-1,rowSize,colSize) && current > matrix[i][j-1] ){
        dpMax = max((DFS(i,j-1, matrix, dp)+1), dpMax);
    }
    //right
    if(check(i,j+1,rowSize,colSize) && current > matrix[i][j+1] ){
        dpMax = max(DFS(i,j+1, matrix, dp)+1, dpMax);
    }
    //up
    if(check(i-1,j,rowSize,colSize) && current > matrix[i-1][j]){
        dpMax = max(DFS(i-1,j, matrix, dp)+1, dpMax);
    }
    //down
    if(check(i+1,j,rowSize,colSize) && current > matrix[i+1][j]){
        dpMax = max(DFS(i+1,j, matrix, dp)+1, dpMax);
    }
    
    dp[i][j] =dpMax;
    return dpMax;
//    if(dpMax==-1){
//        dp[i][j] =0;
//        return 0;
//    }else{
//        dp[i][j] =dpMax;
//        return dpMax;
//    }
}

int longestIncreasingPath(vector<vector<int>>& matrix) {

    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    vector<vector<int>>dp(rowSize, vector<int>(colSize, -1));
    int totalMax=0;

    for(int i=0; i<rowSize; i++){
        for(int j=0; j<colSize; j++){
//            if(dp[i][j]==-1)
//                dp[i][j] = DFS(i,j, matrix,dp);
            totalMax = max(DFS(i,j, matrix,dp), totalMax);
        }
    }
    return totalMax+1;

}


int main(){
    vector<vector<int>>mat = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(mat);
}









//first BruteForce ==> RUNTIME ERROR

//
//int longestIncreasingPath(vector<vector<int>>& matrix) {
//
//    int rowSize = matrix.size();
//    int colSize = matrix[0].size();
//    int localMax=0, totalMax=0;
//    vector<vector<bool>> visited;
//
//    for(int i=0; i<rowSize; i++){
//        for(int j=0; j<colSize; j++){
//            localMax = recursivePath(i,j, matrix,visited);
//            if(localMax>totalMax)
//                totalMax=localMax;
//        }
//    }
//    return totalMax;
//
//}
//
//int recursivePath(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
//    int lmax=0, rmax=0, umax=0, dmax=0;
//    int rowSize = matrix.size();
//    int colSize = matrix[0].size();
//
//    int current= matrix[i][j];
//    visited[i][j]=true;
//    //left
//    if(check(i,j-1,rowSize,colSize) && current <matrix[i][j-1] && !visited[i][j-1]){
//        lmax += recursivePath(i,j-1, matrix,visited);
//    }
//    //right
//    if(check(i,j+1,rowSize,colSize) && current < matrix[i][j+1] && !visited[i][j+1]){
//        rmax += recursivePath(i,j+1, matrix,visited);
//    }
//    if(check(i-1,j,rowSize,colSize) && current < matrix[i-1][j] && !visited[i-1][j]){
//        umax += recursivePath(i-1,j, matrix,visited);
//    }
//    if(check(i+1,j,rowSize,colSize) && current < matrix[i+1][j] && !visited[i+1][j]){
//        dmax += recursivePath(i+1,j, matrix,visited);
//    }
//
//    return max(max(lmax,rmax), max(umax,dmax));
//}
//
//bool check(int i, int j ,int rowSize, int colSize){
//    if(i<0 || i>rowSize-1 || j<0 || j>colSize-1)
//        return false;
//    else
//        return true;
//    }
