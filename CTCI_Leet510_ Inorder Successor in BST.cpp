//
//  CTCI4.cpp
//  graph_dfs
//
//  Created by Mina on 13/07/2019.
//  Copyrigh t © 2019 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 
 The successor of a node p is the node with the smallest key greater than p.val.
 
 You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node.
 
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* left;
 Node* right;
 Node* parent;
 };
 */

Node* inorderSuccessor(Node* node) {
    Node* cur = node;
    
    //When the node has the right node -> get the smallest
    if(right!=NULL){
        cur=node->right;
        
        while(cur->left!=NULL){
            cur=cur->left;
        }
        
        return cur;
        
        //when the node is the right node
    }else{
        
        
        //check if the node is the left node of the parent node. If so, return parent
        //If not, find the ancestor of it
        Node* curParent = cur->parent;
        
        /* <IMPROVEMENT> This part can be shorten by just checking the node->parent->right */
        while(curParent!=NULL){
            //if the node was parent's left -> return parent
            if(curParent->left == cur){
                return curParent;
                
                //if not, keep moving upward
            }else{
                cur = curParent;
            }
        }
        /* <IMPROVEMENT> the root node's parent is already NULL, no need to check, just return the parent(NULL) */

        if(curParent == NULL){
            return NULL;
        }
    }
    
}


//Second version


Node* inorderSuccessor(Node* node) {
    Node* cur = node;
    
    //When the node has the right node -> get the smallest
    if(right!=NULL){
        cur=node->right;
        
        while(cur->left!=NULL){
            cur=cur->left;
        }
        
        return cur;
        
        //when the node is the right node
    }else{
        
        
        //check if the node is the left node of the parent node. If so, return parent
        //If not, find the ancestor of it
        Node* curParent = cur->parent;
        
        /* This part can be shorten by just checking the node->parent->right */
        while(curParent!=NULL && node== curParent->right){
                cur = curParent;
        }
        
        return curParent;
    }
    
}
