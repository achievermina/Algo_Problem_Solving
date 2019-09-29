//
//  Leet939_minRectangle.cpp
//  algo
//
//  Created by Mina on 28/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> yCoordination;
        int x1,x2,y1,y2;
        int yDist =0, xDist=0;
        int area=0, minArea=INT_MAX;
        
        for(auto point:points){
            yCoordination[point[1]].insert(point[0]);
        }
        
        sort(points.begin(), points.end());
        for(int i =1; i<points.size(); i++){
            if(points[i][0]==points[i-1][0]){
                y1=  points[i-1][1];
                y2 = points[i][1];
                
                x1= points[i][0];
                yDist = abs(y1-y2);
                
                if(yDist!=0 && yDist<minArea){
                    set<int>::iterator it1, it2;
                    for(it1=yCoordination[y1].begin(); it1!=yCoordination[y1].end(); it1++){
                        for(it2=yCoordination[y2].begin(); it2!=yCoordination[y2].end(); it2++){
                            if(*it1==*it2 && x1!=*it1 && abs(*it2-*it1)<minArea){
                                x2=*it1;
                                xDist= abs(x1-x2);
                                area= xDist*yDist;
                                minArea=min(area, minArea);
                            }
                        }
                    }
                }
            }
        }
        if(minArea == INT_MAX)
        return 0;
        return minArea;
    }
};
