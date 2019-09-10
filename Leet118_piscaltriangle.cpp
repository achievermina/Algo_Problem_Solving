//
//  Leet118_piscaltriangle.cpp
//  algo
//
//  Created by Mina on 07/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> ele;
        
        if(numRows==0){
            return res;
        }
        
        ele.push_back(1);
        res.push_back(ele);
        
        if(numRows==1)
            return res;
        
        ele.push_back(1);
        res.push_back(ele);
        
        if(numRows==2)
            return res;
        
        for(int i = 2; i<numRows; i++){
            ele.clear();
            ele.push_back(1);
            vector<int> prev = res[i-1];
            for(int j=1; j<prev.size(); j++){
                ele.push_back(prev[j-1]+prev[j]);
            }
            ele.push_back(1);
            res.push_back(ele);
        }
        
        return res;
    }
};
