//
//  CTCI_4_3_ListOfDepts.cpp
//  algo
//
//  Created by Mina on 16/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

/*
 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
 at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 Hints: #107, #123, #135
 */

//CTCI 책 해설을 이해 못하겠음
//BFS (answer2) is similar with my answer

//https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Node{
    
public:
    int key;
    Node* next;
    Node* left;
    Node* right;
    
    Node(int key){
        this->key = key;
        this->next =NULL;
        this->left =NULL;
        this->right =NULL;

    }
};
    
//First idea was using already made-linked list, broaden version of BFS
//IDEATION 만 중요하면 그냥 ArrayList<ListNode<TreeNode> 가정해도됨!
    
    vector<Node*> listOfDepts(Node* root){

        //find a depth. --> 어떻게 하는지?
        int depth = findDepth(root);

        vector<Node*> arrLL; //LL의 array를 만들어서 모든 LL 저장
        arrLL.push_back(addNode(root));

        for(int i =0; i<depth; i++){
            Node* currentParent = arrLL[i];
            Node* currentNode = NULL;

            // Check child while running parents LL

            while(currentParent!=NULL){
                if(currentParent->left!=NULL)
                    currentNode = addNode(currentNode, currentParent->left, arrLL[i+1]);

                if(currentParent->right!=NULL)
                    currentNode = addNode(currentNode, currentParent->right, arrLL[i+1]);

                currentParent=currentParent->next;
            }



        }
        return arrLL;

    }




    Node* addNode(Node* currentNode, Node* addingNode, Node* a ){

        if(currentNode==NULL){
            Node* newNode = new Node(addingNode);
            arrLL[i+1] = newNode;
            return newNode;
        }else{
            currentNode->next = Node(addingNode);
            return currentNode->next;
        }

    }
    
    
    
    
};

    //using queue

class linkedList{
    Node* head=NULL;
    
public:

    
    vector<Node*> listOfDepts(Node* root){
        queue<Node*> q;
        vector<Node*> arrLL;
        int idx=0;
        q.push(root);
        arrLL.push_back(root);
        
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            if(cur!=NULL){
                addNode(arrLL[idx], cur);
                
                if(cur->left!= NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
                
            }else if(!q.empty()){
                idx++;
                q.push(NULL);
            }
        }
        return arrLL;
    }
    
    
    void addNode(Node* currentNode, Node* addingNode){
        if(currentNode==NULL) *currentNode = Node(addingNode->key);
        else{
            while(currentNode->next!=NULL) currentNode= currentNode->next;
            *(currentNode->next) = Node(addingNode->key);
        }
        }
