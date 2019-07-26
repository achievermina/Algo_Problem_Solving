//
//  21_5_fortress_thelongesttreeroot.cpp
//  algo
//
//  Created by Mina on 24/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>

using namespace std;

int longest;

class TreeNode{
    //children in vector
    vector<TreeNode*> children;
    
    //create the tree
    TreeNode* getTree(int root){
        
    }
    
    
    
    //get the height of subtrees from root
    int height(TreeNode* root){
        vector<int> heights;
        
        //searching children vector
        for(int i =0; i<root->children.size(); i++){
            heights.push_back(height(root->children[i]));
        }
        
        if(heights.empty()) return 0;
        
        //When there are more than two nodes, calculate the longest distance between node and node
        //The longest nodes from the left subtree and the longest from the right will be the longest path
        //left longest + right longest +2(each children) +1(root itself)
        
        sort(heights.begin(), heights.end());
        //heights is sorted -> the last two nodes will have the longest path
        if(heights.size()>=2){
            longest = max(longest, heights[heights.size()-1]+heights[heights.size()-2]+2);
        }
        
        return heights.back()+1;
        
        
    }
    
    //to compare the height of the tree vs leaf-leaf path
    int longestHeight(TreeNode* root){
        longest = 0
        int heightOftheTree = height(root);
        return max(longest, heightOftheTree);
        
    }
};


