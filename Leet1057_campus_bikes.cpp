//
//  Leet1057_campus_bikes.cpp
//  algo
//
//  Created by Mina on 02/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>

/*
 On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.
 
 Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.
 
 The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
 
 Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.
 
 
 
 Example 1:
 
 
 
 Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
 Output: [1,0]
 Explanation:
 Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
 */


vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    vector<vector<int>> dist;
    vector<int> ans;
    vector<int> taken = {0};
    
    //calculate the distance
    for(int i =0; i<bikes.size(); i++){
        for(int j=0; j<workers.size(); j++){
            dist[i][j]= abs(bikes[i][0]-workers[j][0]) + abs(bikes[i][1]-workers[j][1]);
        }
    }
    
    for(int i=0, k=0; i<bikes.size(); i++){
        int added = 0 ;
        sorted_arr = sort(dist[i].begin(), dist[i].end());
        for(int j=0; j<workers.size(); j++){
            if(dist[i][j]==sorted_arr[k] && taken[j]==0){
                ans[i] = j ;
                taken[j] =1;
                added=1;
                break;
            }
        }
        if(added ==0) i--, k++;
        
        
    }
}



int main(){
    
    vector<vector<int>> workers = [[0,0],[2,1]];
    vector<vector<int>> bikes = [[1,2],[3,3]];
}
