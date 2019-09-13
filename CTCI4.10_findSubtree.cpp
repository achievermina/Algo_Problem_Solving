//
//  CTCI4.10_findSubtree.cpp
//  algo
//
//  Created by Mina on 09/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>


/* Mina's strategy
 
1. t1 preorder traversal -vector
2. t2 preorder traversal -vector
 -----traversal -> empty leaf-> push NULL
 while
3. find the t2[0] value from t1
 if many, try all
 4. check the structure
 for(i < t2.size())
    if(t2[i]!=NULL && t1[i] !=t2[i])
        return false;

 
 */

//Leet572


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


