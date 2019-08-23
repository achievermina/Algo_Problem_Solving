//
//  973_KclosestPoints.cpp
//  algo
//
//  Created by Mina on 22/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>

////map은 sort가 안되네?
//priority queue 나 다른걸 해야겠다

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        unordered_map<int, vector<int>> map;
        
        for(int i =0; i<points.size(); i++){
            long val = pow(points[i][1],2)+pow(points[i][1],2);
            map.insert(pair<int,vector<int>>(val, points[i]));
        }
        map ap;
        vector<vector<int>> output;
        
        for(int j=0; j<K; j++){
            output.push_back(map[j][1]);
        }
        return output;
    }
};
