//
//  30.cpp
//  algo
//
//  Created by Mina on 16/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>

using namespace std;

#define MAX_V 3;

int V;
vector<pair<int,int>> adj[MAX_V]; //(adjacent edge, weight)

vector<int> bell(int src){
    vector<int> dist(V, INFINITY);
    
    dist[src] = 0;
    bool updated;
    
    for(int i=0; i<V; ++i){ // ++i ==> his part will be used to check if V th is updated or not.
        updated =false;
        
        for(int here=0; here< V; ++here){
            for(int j=0; j<adj[here].size(); j++){
                int there = dist[here][j].first;
                int cost = dist[here][j].second;
                
                if(dist[there]>dist[here]+cost){
                    dist[there] =dist[here]+cost;
                    updated= true;
                }
            }
        }
        
        if(!updated) break;
    }
    
    if(updated) dist.clear(); // after V th, if it is still updated, there is a negative cycle, therefore, delete everything.
    return dist;
}
