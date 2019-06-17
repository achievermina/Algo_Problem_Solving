/*
 
 Developer: Mina
 Last_updeated:  06/05/19
 Title: Directed Graph Traversal to find Strongly connected compoents
 reference: https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/
 https://www.geeksforgeeks.org/strongly-connected-components/

 
 */

//Graph directed graph

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <stack>
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
    
    //recursive explore and DFS
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
    
    
    
    //Save the decreasing order of traversal time using stack
    void traverse(int org, stack<int>* s){
        bool visited[this->v];
        
        
        for(int i=0; i<this->v; i++){
            visited[i]= false;
        }
        
        //first traverse
        explore2(org, visited, s);
        
        //the leftover in order
        for(int i=0; i<this->v; i++){
            if(visited[i]== false){
                explore2(i, visited, s);
            }
        }
        
      
        
    }
    
    void explore2(int org, bool visited[], stack<int>* s){
        visited[org]=true;
        
        list<int>::iterator it;
        for(it= adj[org].begin(); it!= adj[org].end(); it++){
            if(visited[*it]==false){
                explore2(*it,visited, s);
                
                
                
            }
        }
        (*s).push(org); //stack이 정보 저장을 안해서 reference 로 사용
        //stack is for checking the traverse in post-order
        //stack에 넣는 이 부분의 위치가 중요함 -- *it을 넣는게 아니라 org을 넣으면되잖아
        //cout<<org<<" stack in"<<endl;
        //http://www.cplusplus.com/forum/beginner/47794/
        
    }
    
    //Transpose the edges
        //use iterator
    
    graph transpose(){
        graph reversed(this->v);
        
        for(int i=0; i<this->v; i++){
            for(list<int>::iterator it =adj[i].begin(); it!=adj[i].end(); it++){
                reversed.addEdge(*it,i);
            }
        }
        
        return reversed;
    }
    
    
    //ver1 - check if the graph is SC
    //check SC
        // DFS on OG graph - get the post number
        // Transpose
        // DFS on reversed Graph
    
    
    //ver2 - find the strongly connectec graph
        //using array connect each vertex with the index of SCC
    int SCC(int org){
        
        //int numSC[this->v];
        bool visited[this->v];
        int SCC=0, source;
        
        //set up visited
        for(int i=0; i<this->v; i++){
            visited[i]= false;
        }

        //transpose the graph
        graph reversed = transpose();
        //cout<<"revesed graph "<<endl;
        //reversed.printGraph();
        
        stack<int> reversedPostOrder;
        reversed.traverse(org,&reversedPostOrder);
        

        
        //original graph
        while(!reversedPostOrder.empty()){
            source = reversedPostOrder.top();
            if(visited[source]==false){
                SCC++;
                explore(source, visited);
            }
            reversedPostOrder.pop();
        }
        return SCC;
    
    }
    
    void printGraph(){
        
        for(int i=0; i<this->v; i++){
            
            cout<<"vertex "<<i<<endl;
            for(list<int>::iterator it = adj[i].begin(); it!= adj[i].end(); it++){
                cout<<" to "<<(*it)<<endl;
            }
        }
        
    }
};

int main(){
    
    graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(3, 0);

    gh.DFS(1);
    
    gh.printGraph();
    
    cout<<"The number of SCC is "<<endl;
    cout<<gh.SCC(1)<<endl; //Correct answer is 3
    
}

