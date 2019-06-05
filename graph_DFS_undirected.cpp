/*
 
 Developer: Mina
 Last_updeated:  05/28/19
 Title: Undirected Graph Setup
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
    int id;
    bool visited;
    int count;
    struct node *next;
};


class graph{
private:
    struct adjArr* adjList;
    int V; //the number of vertex
    
    
public:
    graph(int V){ //constructor with graph of vertices V
        this->V = V;
        adjList = new adjArr[V];
        for(int i=0; i<V; ++i){
            node* newHead = initialize(i);
            adjList[i].head = newHead;
        }
    }
    
    
    node* initialize(int dest){
        
        node* newNode = new node();
        newNode->id = dest;
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
    
    
    void explore(int org, int visited[]){
        
        node* head = adjList[org].head;
        head->visited = true;
        head->count = ++countTime;
        
        visited[org]=true;

        
        while(head->next != NULL && head->next != adjList[org].head){
            cout<<org<<" visited\n";

            org = head->id;
            head = head->next;
            if(visited[org]==false)
                explore(org, visited);
        }
    }
    
    void DFS(int org){
        
        int visited[this->V];
        
        for(int i=0; i<=this->V; i++){
            visited[i]=false;
        }
        
        explore(org, visited);
        
        
    }
    
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                node* pCrawl = adjList[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->id;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
};





int main() {
    
    graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.printGraph();

    //    gh.addEdge(1, 4);
    //    gh.addEdge(2, 3);
    //    gh.addEdge(3, 4);
    
    gh.DFS(1);
    
    return 0;
}
