//
//  Leet141_hasCycle.cpp
//  algo
//
//  Created by Mina on 03/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//NO Need to use do-while
//you can use only while

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        if(head==NULL || head->next ==NULL)
            return false;
        
        //check cycle
        do{
            slow= slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
            else
                return false;
            
        }while(slow!=NULL && fast!=NULL && slow!=fast);
        
        if(slow==fast && slow!=NULL ){
            return true;
        }else
            return false;
    }
};


/*
 reference:https://leetcode.com/problems/linked-list-cycle/discuss/44604/My-faster-and-slower-runner-solution
 
 bool hasCycle(ListNode *head) {
 if(head == NULL || head -> next == NULL)
 return false;
 
 ListNode *fast = head;
 ListNode *slow = head;
 
 while(fast -> next && fast -> next -> next){
 fast = fast -> next -> next;
 slow = slow -> next;
 if(fast == slow)
 return true;
 }
 
 return false;
 }
 
 */
