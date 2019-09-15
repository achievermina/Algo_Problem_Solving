//
//  graph_KruskalsMST_UnionFind.cpp
//  algo
//
//  Created by Mina on 26/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

// 뭔가 그래프의 weight 부분이 클리어하지 않아서 ㅂㅔ끼지도 못함
//reference: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
//java ref: https://algorithms.tutorialhorizon.com/kruskals-algorithm-minimum-spanning-tree-mst-complete-java-implementation/

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int src_, int dest_, int weight_): src(src_), dest(dest_), weight(weight_){}
    
};

class Graph
{
public:
    int V, E;
    Edge* edge;
    
    createGraph(int V, int E){
        Graph* graph = new Graph;
        graph->V = V;
        graph->E = E;
        
        graph->edge = new Edge[E];
        
        return graph;
    }
    
};


//UNION FIND
class subset{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i){
    if(subsets[i].parent ==i)
        return i;
    return find(subsets, subsets[i].parent);
}

void merge(subset subsets[], int x, int y){
    int rootx = find(subsets, x);
    int rooty = find(subsets, y);
    
    //compare the rank
    //same rank
    if (subsets[rootx].rank == subsets[rooty].rank){
        subsets[rooty].parent = rootx;
        subsets[rootx].rank++;
    }
    
    //diff rank
    if(subsets[rootx].rank > subsets[rooty].rank){
        subsets[rooty].parent = rootx;
    }else{
        subsets[rootx].parent = rooty;
    }
}


subset create(
