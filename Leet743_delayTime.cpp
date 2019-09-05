//
//  Leet743_delayTime.cpp
//  algo
//
//  Created by Mina on 03/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;


    
//ref: https://leetcode.com/problems/network-delay-time/discuss/251861/python-10-line-Optimized-Djikstra-solution-and-8-line-Bellman-Ford

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> dist(N+1, INT_MAX);
    
    dist[K] =0;
    
    for(int i =1; i<N+1; i++){
        for(auto edge : times){
            int u=edge[0], v=edge[1], w=edge[2];
            
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    
    sort(dist.begin(), dist.end());
    if(dist[N-1]!= INT_MAX)
        return dist[N-1];
    else
        return -1;
    
    
    
}

int main(){
    
    vector<vector<int>> s = {{2,1,1}, {2,3,1},{3,4,1}};
    cout<<networkDelayTime(s,4,2);
    
    
    
}
