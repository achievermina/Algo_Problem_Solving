//
//  Leet797_allPathsSourceTarget.cpp
//  algo
//
//  Created by Mina on 18/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 
 The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
 
 Example:
 Input: [[1,2], [3], [3], []]
 Output: [[0,1,3],[0,2,3]]
 Explanation: The graph looks like this:
 0--->1
 |    |
 v    v
 2--->3
 There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 Note:
 
 The number of nodes in the graph will be in the range [2, 15].
 You can print different paths in any order, but you should keep the order of nodes inside one path.
 */

void DFS(int src, vector<vector<int>>& graph,vector<vector<int>>& allpath,vector<int>& path,vector<int>& visited) {
    if(src == graph.size()-1){
        allpath.push_back(path);
    }else{
        for(int j=0; j<graph[src].size(); j++){
            int newsrc =graph[src][j];
            if(visited[newsrc]!=1){
                visited[newsrc]=1;
                path.push_back(newsrc);
                DFS(newsrc, graph, allpath, path, visited);
                path.pop_back();
                visited[newsrc]=0;
            }
        }
    }
    
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
    vector<int> visited(graph.size(), 0);
    vector<int> path;
    vector<vector<int>> allpath;
    
    if(graph.size()<2)
        exit(1);
    
    path.push_back(0);
    for(int i =0; i<graph[0].size(); i++){
        path.push_back(graph[0][i]);
        DFS(graph[0][i], graph, allpath, path, visited);
        path.pop_back();
    }
    
    return allpath;
    
}
