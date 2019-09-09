//
//  Leet59_spiralMatrix2.cpp
//  algo
//
//  Created by Mina on 09/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n,vector<int>(n,1));
    
    if(n<=1)
        return matrix;
    
    int number =1;
    int i =0, j=0;
    int rb =n-1, lb=0, db=n-1, ub=0;
    vector<vector<int>> dirt={{0,1},{1,0},{0,-1},{-1,0}};
    int dirtIdx =0;
    
    while(number<=n*n){
        
        
        while(i<=db && i>=ub && j<=rb &&j>=lb){
            
            
            matrix[i][j] =number;
            number++;
            
            i += dirt[dirtIdx][0];
            j += dirt[dirtIdx][1];
        }
        
        if(dirtIdx==0) {ub++; i++; j--;}
        if(dirtIdx==1) {rb--; j--; i--;}
        if(dirtIdx==2) {db--; i--; j++;}
        if(dirtIdx==3) {lb++; j++; i++;}
        
        dirtIdx++;
        dirtIdx = (dirtIdx)%4;
        
        
    }
    return matrix;
    
    
    
}
int main(){
    generateMatrix(3);
}
