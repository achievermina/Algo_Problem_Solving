//
//  Leet746_minCostClimbingStairs.cpp
//  graph_dfs
//
//  Created by Mina on 24/06/2019.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int minCostClimbingStairs(vector<int>& cost) {
    vector<int> mem;
    int costSize = cost.size();
    
    mem.push_back(cost[0]);
    mem.push_back(cost[1]);

    for(int i =2; i<costSize; i++){
        int mem_min = min(mem[i-1]+cost[i], mem[i-2]+cost[i]);
        mem.push_back(mem_min);
    }
    
    return min(mem[costSize-1], mem[costSize-2]);
}

int main(){
    vector<int> cost;
//    cost.push_back(1);
//    cost.push_back(100);
//    cost.push_back(1);
//    cost.push_back(1);
//    cost.push_back(1);
//    cost.push_back(100);
//    cost.push_back(1);
//    cost.push_back(1);
//    cost.push_back(100);
//    cost.push_back(1);

    cost.push_back(0);
    cost.push_back(0);
    cost.push_back(0);
    cost.push_back(1);
    cout<<"The min number of steps is "<<minCostClimbingStairs(cost)<<endl;
}
