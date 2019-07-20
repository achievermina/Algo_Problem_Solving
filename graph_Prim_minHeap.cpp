//
//  graph_Prim_minHeap.cpp
//  algo
//
//Reference : https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/
//For prims's algorithm - minWeight can use priority queue or minHeap

#include <iostream>
#include <cmath>
using namespace std;

//adj
//Heap

/*
MinHeapNode {
    int v;
    int key;
};
*/


//prim's MST

vector<int> primMST(Graph* graph, int src){
    int V =graph->V;
    int prev[V];
    bool added[V] ={false};
    vector<int> MST;
    
    minHeap* mh = createMinHeap(graph);
    
    //source
    added[src] = true;
    prev[src] = src;
    MST.push_back(src);
    
    //update key
    while(!mh.empty()){
        int u= getMinVertex();
        added[u] = true;
        
        for(int v =0; adj[u].size(); v++){
            if(!added[v] && (mh.findKey(u)+adj[u][v]< mh.findKey(v)){
                mh.updateKey(v, findKey(u)+adj[u][v]);
                prev[v] = u;
            }
        }
    }
               
    
    
    
}
