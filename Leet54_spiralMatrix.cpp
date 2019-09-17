//
//  Leet54_spiralMatrix.cpp
//  algo
//
//  Created by Mina on 08/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if(matrix.size()<0)
            return res;
        int m = matrix.size();
        int  n= matrix[0].size();
        int firstcol=0, firstrow=0;
        int lastcol = n-1, lastrow=m-1;
        int curcol=0, currow=0;
        
        while(res.size()<m*n){
            
            //right
            while(curcol<=lastcol){
                res.push_back(matrix[currow][curcol]);
                if(curcol==lastcol)
                    break;
                else
                    curcol++;
            }
            currow++;
            firstrow++;
            
            if(check(firstcol, lastcol, firstrow, lastrow)) break;
            
            //down
            while(currow<=lastrow){
                res.push_back(matrix[currow][curcol]);
                if(currow==lastrow)
                    break;
                else
                    currow++;
            }
            lastcol--;
            curcol--;
            
            if(check(firstcol, lastcol, firstrow, lastrow)) break;
            
            //left
            while(curcol>=firstcol){
                res.push_back(matrix[currow][curcol]);
                if(curcol==firstcol)
                    break;
                else
                    curcol--;
            }
            lastrow--;
            currow--;
            
            if(check(firstcol, lastcol, firstrow, lastrow)) break;
            
            //up
            while(currow<=firstrow){
                res.push_back(matrix[currow][curcol]);
                if(currow==firstrow)
                    break;
                else
                    currow--;
            }
            firstcol++;
            curcol++;
            
            if(check(firstcol, lastcol, firstrow, lastrow)){
                res.push_back(matrix[currow][curcol]);
                break;
            }
        }
        return res;
    }
    
    bool check(int fcol, int lcol, int frow, int lrow){
        if(fcol==lcol && frow==lrow && fcol==frow)
            return true;
        else
            return false;
    }
};
