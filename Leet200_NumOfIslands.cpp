/*

Leetcode 200.Number of Islands
6/1/2019

*/


class Solution {
public:


    void check(vector<vector<char>>& grid, int (*dpArray)[][], int x, int y, int Num){      

        if(grid[x][y]==1){
           dpArray[x][y] = Num;

           if(x>0 && dpArray[x-1][y]!=0) check(grid, dpArray, x-1, y, Num);
           if(x<grid[0].size() && dpArray[x+1][y]!=0) check(grid, dpArray, x+1, y, Num);
           if(y>0 && dpArray[x][y-1]!=0) check(grid, dpArray, x, y-1, Num);
           if(y<grid.size() && dpArray[x][y+1]!=0) check(grid, dpArray, x, y+1, Num);
       }
    }

    int numIslands(vector<vector<char>>& grid) {

        int num =0;
        int rowSize = grid.size();
        int columnSize = grid[0].size();
        
        int dpArray[columnSize][rowSize];
        for(int x =0; x<columnSize; x++){
            for(int y=0; y<rowSize; y++){
                dpArray[x][y]=0;
            }
        }
        

        for(int x =0; x<columnSize; x++){
            for(int y=0; y<rowSize; y++){
                if(grid[x][y]==1 && dpArray[x][y]==0){
                    check(grid, dpArray, x, y, num);
                }
            }
        }
        
    }
};