//
//  29.4_sortingGame_BFS.cpp
//  algo
//
//  Created by Mina on 13/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>

using namespace std;

void reverse(int start, int end);

void bfs(const vector<int>& perm){
    int n = perm.size();
    
    
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    
    queue<vector<int>> q;
    map<vector<int>, int> distance;
    
    distance[perm] = 0;
    q.push(perm);
    
    while(!q.empty()){
        vector<int> here = q.front();
        q.pop();
        
        if(here==sorted) return distance[here];
        
        int cost = distance[here];
        
        for(int i =0; i<n; ++i){
            for(int j =i+2 ; j <= n; ++j ){
                reverse(here.begin()+i, here.begin()+j);
                if(distance.count(here)==0){//if not in the map
                    distance[here] = cost +1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);

            }
            
        }
    }
}
