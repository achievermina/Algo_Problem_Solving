//
//  CTCI_2_2_kthlastelement.cpp
//  algo
//
//  Created by Mina on 16/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

class Node{
    
public:
    char key;
    Node* next;
    
    Node(int key){
        this->key = key;
        this->next =NULL;
    }
};


class linkedList{
    Node* head=NULL;
    
public:
    Node* findKthLastValue(int k, Node* root){
        Node* cur = root;
        Node* k_cur = root;
        int idx = 1;
        
        while(cur->next!=NULL){
            cur=cur->next;
            idx++;
            
            if(idx>=k){
                k_cur=k_cur->next;
            }
        }
        return k_cur;
    }
    
    
    
};


//Also, using for loop, you can move the first pointer first

/*
for (int i= 0; i < k; i++) {
    if (pl == null) return null; // Out of bounds
    pl = pl.next;

while (pl!= null) {
    pl pl.next;
    p2 = p2.next;
    return p2;
}
*/
