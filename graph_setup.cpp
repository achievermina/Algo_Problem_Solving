/*
 
 Developer: Mina
 Last_updeated:  05/28/19
 Title: Graph
 reference: https://www.sanfoundry.com/cpp-program-implement-adjacency-list
 
 */


#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int countTime=0;

struct adjArr{
    struct node* head;
};

struct node{
    int dest;
    bool visited;
    int count;
    struct node *next;
};


class graph{
private:
    struct adjArr* adjList;
    int V;

    
public:
    graph(int V){ //constructor with graph of vertices V
        this->V = V;
        adjList = new adjArr[V];
        for(int i=0; i<V; ++i){
            adjList[i].head = NULL;
        }
    }
    
    
    node* initialize(int dest){
        
        node* newNode = new node();
        newNode->dest = dest;
        newNode->visited = false;
        newNode->count = 0;
        newNode->next = NULL;
        return newNode;
    }
    
    void addEdge(int org, int dest){
        node* newNode = initialize(dest);
        newNode->next = adjList[org].head;
        adjList[org].head = newNode;
        
        node* newNode2 = initialize(org);
        newNode2->next = adjList[dest].head;
        adjList[dest].head = newNode2;

    }
    
    
    vector<int> explore(int graph, int org){
        vector<int> visitedVertex;
        
        node* head = adjList[org].head;
        head->visited = true;
        head->count = countTime++;
        
        while(head->next == NULL){
            visitedVertex.push_back(head->dest);
            head = head->next;
        }
        return visitedVertex;
    }

    
};




int main() {

    graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
    
    return 0;
}
