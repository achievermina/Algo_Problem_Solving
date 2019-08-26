//
//  Leet510_inorderSuccessor.cpp
//  algo
//
//  Created by Mina on 25/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


//그냥 오른쪽있는지 보고
//없으면 그냥 계속 왼쪽에 위치할 때까지 올라가면 됨


Node* inorderSuccessor(Node* node) {
    Node* cur =node;
    
    if (!node)
        return NULL;
    
    //if right node exists
    if(node->right){
        cur = node->right;
        while(cur->left) cur=cur->left;
        return cur;
    }
    
    //if not, check the parent
    
    //the node is the root
    if(!node->parent)
        return NULL;
    
    
    cur=node;
    while(cur->parent && cur->parent->left !=cur){
        cur= cur->parent;
    }
    return cur->parent;
    
    
    
}


///////NO NEED TO DO THIS

/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* left;
 Node* right;
 Node* parent;
 };
 */
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* cur =node;
        int check =0;   //left 1, right 2, root 3
        
        if (!node)
            return NULL;
        
        
        
        
        if(!node->parent){
            cur= cur->right;
            while(cur && cur->left) cur=cur->left;
            return cur;
        }else if(node->parent->right ==node){
            check=2;
        }else if(node->parent->left == node){
            check=1;
        }
        
        
        
        switch(check){
            case 1:
                if(node->right){
                    cur = node->right;
                    while(cur->left) cur=cur->left;
                    return cur;
                }else{
                    return node->parent;
                }
                break;
                
            case 2:
                if(node->right){
                    cur = node->right;
                    while(cur->left) cur=cur->left;
                    return cur;
                }else{
                    cur=node;
                    while(cur->parent->parent && cur->parent->parent->right ==cur->parent){
                        cur= cur->parent;
                        if(!cur->parent->parent)
                            return NULL;
                    }
                    return cur->parent;
                }
                break;
        }
        return NULL;
    }
};
