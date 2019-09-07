//
//  Leet63_uniquePath2.cpp
//  algo
//
//  Created by Mina on 05/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    double uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        if(obstacleGrid.size()<1)
            return 0;
        
        int row= obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        if(obstacleGrid[row-1][col-1]==1)
            return 0;
        
        vector<vector<double>> dp(row,vector<double>(col,0.0));
        
        //initialization
        //첫 row나 콜롬에서 블럭이 있으면 그 뒤는 다 block
        for(int i=0; i<row; i++){
            if(obstacleGrid[i][0]==1){
                dp[i][0]=-1;
                break;
            }else
                dp[i][0]=1;
        }
        
        for(int j=0; j<col; j++){
            if(obstacleGrid[0][j]==1){
                dp[0][j]=-1;
                break;
            }else
                dp[0][j]=1;
            
        }
        
        //special cases
        if(row==1 && col==1){
            if(obstacleGrid[0][0] ==0)
                return 1;
            else
                return 0;
        }else if((row==1 ||col==1) && (dp[row-1][col-1]==-1 ||dp[row-1][col-1]==0))
            return 0;
        
        
        //calculation
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(obstacleGrid[i-1][j]==1 && obstacleGrid[i][j-1]==1)
                    dp[i][j]=0;
                else if(obstacleGrid[i-1][j]==1)
                    dp[i][j]=dp[i][j-1];
                else if(obstacleGrid[i][j-1]==1)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
            }
        }
        
        
        
        return dp[row-1][col-1];
    }
};
