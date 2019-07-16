//
//  Leet_uber_distanceOfTheNearest0.cpp
//  algo
//
//  Created by Mina on 14/07/2019.
//  Copyright © 2019 Mina. All rights reserved.

/*
 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell
 The distance between two adjacent cells is 1.
 Input:
 [[0,0,0],
 [0,1,0],
 [1,1,1]]
 
 Output:
 [[0,0,0],
 [0,1,0],
 [1,2,1]]
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDP(vector<vector<int>>& outputMatrix, int i, int j, int colSize, int rowSize){
    if(i<0 || j<0 || i>colSize-1 || j>rowSize-1)
       return max(colSize, rowSize)+100;
    else
        return outputMatrix[i][j];
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int rowSize = matrix.size();
    int colSize= matrix[0].size();
    
    vector<vector<int>> outputMatrix(rowSize, vector<int>(colSize, -1));
    int left, right, up, down;

    //fill up the output matrix
    for(int i =0; i<rowSize; i++){
        for (int j=0; j<colSize; j++){
            
            if(matrix[i][j]==0){
                outputMatrix[i][j]=0;
                }else{
                    //이 네가지 케이스를 만족하기가 쉽지 않아 그래서 각자 케이스에 대해 함수를 만들어서 한번에 처리하게 함
    //                if(i<=0 || j<=0 || i>=colSize-1 || j>=rowSize-1){
    //                up =outputMatrix[i-1][j];
    //                down =outputMatrix[i+1][j];
    //                left = outputMatrix[i][j-1];
    //                right = outputMatrix[i][j+1];
                    
                    left = getDP(outputMatrix, i,j-1, colSize,rowSize);
                    down =getDP(outputMatrix, i+1,j,colSize,rowSize);

                    outputMatrix[i][j]= 1+ min(down, left);
                }
            }
        }
    
    
        for(int i =rowSize-1; i>=0; i--){
            for (int j=colSize-1; j>=0; j--){
                
                    right = getDP(outputMatrix, i,j+1,colSize,rowSize);
                    up =getDP(outputMatrix,i-1,j,colSize,rowSize);
                
                    outputMatrix[i][j]= min(outputMatrix[i][j],1+min(up, right));
            }
        }
    
        return outputMatrix;
    
    }
    


    /* FIRST ATTEMPT
    
     //표를 채우는게 그전의 dp표를 이용하는게 아니라 recursive하게 다시 이용하는 거여서 오래 걸림

int mem(vector<vector<int>>& matrix, vector<vector<int>>& outputMatrix, int i, int j){
    
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    int left, right, up, down;
    
    //Base
    if(outputMatrix[i][j]!=-1) return outputMatrix[i][j];
    
    if(matrix[i][j]==0){
        outputMatrix[i][j]=0;
        return 0;
        
    }else{
        // 여기를 함수로 만들었다면 더 좋았을듯!
        if(j==0){
            left = max(colSize, rowSize)+100;
        }else if(j==rowSize-1){
            right = max(colSize, rowSize)+100;
        }else{
            left = mem(matrix,outputMatrix, i,j-1);
            right = mem(matrix,outputMatrix, i,j+1);
        }
        
        
        if(i==0){
            up = max(colSize, rowSize)+100;
        }else if(i==colSize-1){
            down = max(colSize, rowSize)+100;
        }else{
            up =mem(matrix,outputMatrix, i-1,j);
            down =mem(matrix,outputMatrix, i+1,j);
        }
        
        return min(min(min(left, right),up),down) +1;
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    
    int rowSize = matrix.size();
    int colSize= matrix[0].size();
    
    vector<vector<int>> outputMatrix(rowSize, vector<int>(colSize, -1));
    
    //표를 채우기
    for(int i =0; i<rowSize; i++){
        for (int j=0; j<colSize; j++){
            if(outputMatrix[i][j]==-1)
                outputMatrix[i][j]=mem(matrix, outputMatrix, i,j);
        }
    }
    
    return outputMatrix;
}


*/
