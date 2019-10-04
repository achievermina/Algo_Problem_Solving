//
//  Leet138_copyListwithRandomPointer.cpp
//  algo
//
//  Created by Mina on 30/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node() {}
 
 Node(int _val, Node* _next, Node* _random) {
 val = _val;
 next = _next;
 random = _random;
 }
 };
 */

//Second Attempt
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<int, Node*> map;
        
        if(head==NULL) return NULL;
        
        Node** newHead = NULL;
        Node* cur=head;
        
        Node* temp = new Node(cur->val, NULL, NULL);
        map[(cur->val)] = temp;
        newHead = &temp;
        
        Node* newNodeCur= *newHead;
        
        
        while(cur!=NULL){
            //cur next
            if(cur->next!=NULL){
                if(map.count((cur->next->val))>0){
                    newNodeCur->next = map[(cur->next->val)];
                }else{
                    Node* temp = new Node(cur->next->val, NULL, NULL);
                    map[(cur->next->val)] = temp;
                    newNodeCur->next = temp;
                }
            }else{
                newNodeCur->next =NULL;
            }
            
            //cur random
            if(cur->random==NULL){
                newNodeCur->random = NULL;
            }else if(map.count((cur->random->val))>0){
                newNodeCur->random = map[(cur->random->val)];
            }else{
                Node* randtemp = new Node((cur->random->val), NULL, NULL);
                map[(cur->random->val)] = randtemp;
                newNodeCur->random = map[(cur->random->val)];
            }
            
            newNodeCur = newNodeCur->next;
            cur= cur->next;
            
        }
        return *newHead;
        
    }
};


