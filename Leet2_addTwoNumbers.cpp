//
//  Leet2.cpp
//  algo
//
//  Created by Mina on 21/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* cur3 = NULL;
    ListNode* newHead =NULL;
    int passingDigit =0;
    int val=0;
    
    while(cur1 && cur2){
        //add new node
        val = cur1->val + cur2->val +passingDigit;
        passingDigit =0;
        
        if(val>=10){
            val-=10;
            passingDigit+=1;
        }
        
        ListNode* newNode = new ListNode(val);
        val=0;
        
        if(cur3==NULL){
            newHead = newNode;
            cur3=newNode;
        }else{
            cur3->next = newNode;
            cur3=cur3->next;
        }
        
        cur1=cur1->next;
        cur2=cur2->next;
    }
    
    if(!cur1 && cur2){
        while(cur2){
            val = cur2->val + passingDigit;
            passingDigit =0;
            if(val>=10){
                val-=10;
                passingDigit+=1;
            }
            ListNode* newNode = new ListNode(val);
            cur3->next = newNode;
            cur3=cur3->next;
            cur2=cur2->next;
        }
    }else if(cur1 && !cur2){
        while(cur1){
            val = cur1->val +passingDigit;
            passingDigit =0;
            if(val>=10){
                val-=10;
                passingDigit+=1;
            }
            ListNode* newNode = new ListNode(val);
            cur3->next = newNode;
            cur3=cur3->next;
            cur1=cur1->next;
            
        }
        
    }
    
    if(passingDigit==1){
        ListNode* newNode = new ListNode(passingDigit);
        cur3->next = newNode;
        cur3=cur3->next;
    }
    
    
    return newHead;
}
