//
//  28.cpp
//  graph_dfs
//
//input
//3
//4
//dog
//god
//dragon
//need
//3
//aa
//ab
//bb
//2
//ab
//cd


//output
//need dog god dragon
//aa ab bb
//IMPOSSIBLE

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// make Graph with adj matrix, word start and end

vector<vector<int>> adj;
vector<int> indegree, outdegree; // the number of words which starts/ends with 'i'
vector<string> graph[26][26];  // The matrix which can contain the vector of strings- save the words starts with i, j alphabets

//create a graph

void createGraph(const vector<string>& words){ //get all the input words  //NOT JUST STRING -> VECTOR<string>
    
    // Initialize the variables
    int size = words.size();
    for(int i=0; i<26; i++){
        for( int j=0; j<26; j++){
            graph[i][j].clear(); //이게 뭐하는거지?
        }
    }
    //wrong version: adj = vector<int>(26, vector<int>(26,0))
    adj= vector<vector<int>>(26, vector<int>(26,0));
    indegree = vector<int>(26,0);
    outdegree = vector<int>(26,0);

    //Insert new values
    
    for(int k =0; k<size; k++){
        int a = words[k][0]-'a';
        int b = words[k][(words[k].size()-1)] - 'a';
        
        graph[a][b].push_back(words[k]);
        adj[a][b]++;
        indegree[a]++;
        outdegree[b]++;
        
        
    }
    
}



