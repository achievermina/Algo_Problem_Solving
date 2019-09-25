//
//  Leet572_subtreeOftree.cpp
//  algo
//
//  Created by Mina on 25/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// FIRST ATTEMPT--faster


class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL && t==NULL)
            return true;
        else if(s==NULL || t==NULL)
            return false;
        else
            return traversal(s,t);
    }
    
    bool traversal(TreeNode* s, TreeNode* t){
        if(s==NULL)
            return false;
        
        if(s->val ==t->val){
            bool res = match(s,t);
            if(res) return true;
        }
        return traversal(s->left, t) || traversal(s->right, t);
    }
    
    bool match(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL)
            return true;
        else if(s==NULL || t==NULL)
            return false;
        else if(s->val == t->val){
            return match(s->left, t->left) && match(s->right, t->right);
        }else
            return false;
    }
    
    
    
    
};

//Second attempt -with traversal

//class Solution {
//public:
//    //When no value is the same in Tree s
//    bool isSubtree(TreeNode* s, TreeNode* t) {
//
//        stack<TreeNode*> s1, s2, t1;
//        TreeNode *sNode, *s2Node, *tNode;
//        bool flag=true;
//
//        if(t==NULL && s==NULL)
//            return true;
//
//        s1.push(s);
//
//        while(!s1.empty()){
//            sNode = s1.top();
//            s1.pop();
//
//            cout<<sNode->val<<endl;
//
//            if(sNode->val==t->val){
//                //check
//                s2.push(sNode); t1.push(t);
//
//                while(!s2.empty() && !t1.empty()){
//                    s2Node=s2.top(); s2.pop();
//                    tNode=t1.top(); t1.pop();
//                    if(s2Node->val == tNode->val){
//                        flag=true;
//                        if((s2Node->right)) s2.push(s2Node->right);
//                        if((s2Node->left)) s2.push(s2Node->left);
//                        if((tNode->right)) t1.push(tNode->right);
//                        if((tNode->left)) t1.push(tNode->left);
//                    }else{
//                        flag=false;
//                        break;
//                    }
//
//                }
//
//                if(flag==true && s2.empty() && t1.empty())
//                    return true;
//                else{
//                    while(!s2.empty()) s2.pop();
//                    while(!t1.empty()) t1.pop();
//                }
//
//            }
//
//            if((sNode->right)) s1.push(sNode->right);
//            if((sNode->left))  s1.push(sNode->left);
//
//        }
//
//        return false;
//    }
//
//};

