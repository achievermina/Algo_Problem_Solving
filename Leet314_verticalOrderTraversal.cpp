//
//  Leet314_verticalOrderTraversal.cpp
//  algo
//
//  Created by Mina on 19/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    map<int, vector<int>> indexSet; //save node values per index
    map<TreeNode*, int> treeindex; // keep track node index
    
    if(!root)
        return res;
    
    //Run DFS
    queue<TreeNode*> q;
    int index=0;
    
    q.push(root);
    indexSet[index].push_back(root->val);
    treeindex[root] = index;
    
    while(!q.empty()){
        TreeNode* cur= q.front();
        index= treeindex[cur];
        q.pop();
        
        if(cur->left){
            q.push(cur->left);
            indexSet[index-1].push_back(cur->left->val);
            treeindex[cur->left] = index-1;
        }
        
        if(cur->right){
            q.push(cur->right);
            indexSet[index+1].push_back(cur->right->val);
            treeindex[cur->right] = index+1;
        }
        
    }
    
    map<int, vector<int>>::iterator it;
    
    for(it=indexSet.begin(); it!=indexSet.end(); it++){
        res.push_back(it->second);
    }
    
    return res;
    
    
}
