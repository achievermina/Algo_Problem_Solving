/*
 
 Developer: Mina
 Last_updeated:  05/28/19
 Title: Directed Graph Setup with adjacency list form using list<int>
 reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

 */


#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

class graph{
    
private:
    int v;
    list<int> *adj;
    
public:
    //constructor
    graph(int v){
        this->v = v;
        this->adj = new list<int>[v];
    };
    
    //Add edge
    void addEdge(int org, int dest){
        adj[org].push_back(dest);
    }
    
    void explore(int org, bool visited[]){
        
        visited[org] = true;
        cout<<org<<" visited\n";
        
        list<int>::iterator it;
        for(it=adj[org].begin(); it!=adj[org].end(); it++){ //iterator uses binary expression
            if(visited[(*it)] == false){
                explore(*it, visited);
            }
        }
    }
    
    void DFS(int org){
        bool visited[this->v];
        
        for(int i=0; i<this->v; i++){
            visited[i]= false;
        }
        
        explore(org, visited);
            
    }
    
    
};

int main(){
    
    graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);

    gh.DFS(1);
    
    
}
