//
//  algo28.cpp
//  graph_dfs
//
//  Created by Mina on 04/07/2019.
//


#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;


vector<vector<int>> adj;

void makeGraph(const vector<string>& words){
    adj = vector<vector<int>>(26, vector<int>(26,0)); //adjacency matrix
    
    for(int j=1; j<words.size(); ++j){ // get input words
        int i =j-1;
        int len =(int) min(words[i].size(), words[j].size());
        
        for(int k=0; k<len; ++k){ // check why words[i] comes in front of words[j]
            if(words[i][k]!=words[j][k]){
                int a = words[i][k] -'a';
                int b=words[j][k] - 'a';
                
                adj[a][b] = 1;
                break;
            }
        }
        
    }
                    
}


void dfs(int here){
    
}
