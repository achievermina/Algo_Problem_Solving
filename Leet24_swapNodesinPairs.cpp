//
//  Leet24_swapNodesinPairs.cpp
//  graph_dfs
//
//  Created by Mina on 04/07/2019.
//Given a linked list, swap every two adjacent nodes and return its head.
//You may not modify the values in the list's nodes, only nodes itself may be changed.
#include <iostream>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



//Need to fix!!!
//[1,2,3,4]
//Output
//[1,3,2,4]
//Expected
//[2,1,4,3]
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //check the number of nodes
        ListNode* cur=head;
        int count;
        if(head!=NULL) count=1;
        else
            return head;
        
        while(cur->next!=NULL){
            count++;
            cur= cur->next;
        }
        
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = head->next->next;
        ListNode* origin = head;
        
        
        {first->next = third;
            second->next = third->next;
            third-> next= second;
            
            
        }while(second->next!=NULL){
            first = first->next->next;
            second = second->next;
            third = third->next->next->next;
        }
        
        
        return head;
        
    }
};
