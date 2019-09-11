//
//  Leet199_rightSideView.cpp
//  algo
//
//  Created by Mina on 10/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


//Traversal --> recursion

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void rightPreorder(TreeNode* cur, int level, vector<int>& res){
        if(cur==NULL)
            return;
        
        if(level>res.size()){
            res.push_back(cur->val);
        }
        
        rightPreorder(cur->right, level+1,res);
        rightPreorder(cur->left, level+1,res);
        
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if(root==NULL){
            return res;
        }
        rightPreorder(root, 1, res);
        return res;
    }
};


////refer: https://leetcode.com/problems/binary-tree-right-side-view/discuss/56003/My-C%2B%2B-solution-modified-preorder-traversal
//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root) {
//        vector<int> res;
//        TreeNode* cur = root;
//
//        if(root==NULL)
//            return res;
//
//        if(!(root->left) && !(root->right)){
//            res.push_back(root->val);
//            return res;
//        }
//
//        res.push_back(cur->val);
//        while((cur->left) || (cur->right)){
//
//            if(cur->right){
//                cur=cur->right;
//            }else{
//                cur=cur->left;
//            }
//            res.push_back(cur->val);
//
//        }
//        return res;
//    }
//};
