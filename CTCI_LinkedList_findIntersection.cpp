//
//  CTCI_LinkedList_findIntersection.cpp
//
//  Created by Mina on 17/06/2019.

//  Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­secting node. Note that the intersection is defined based on reference, not value.That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
//


#include <iostream>
using namespace std;

class ListNode{

public:
    int key;
    ListNode* next;
    
    ListNode(int key){
        this->key = key;
        this->next =NULL;
    }
};


class linkedList{
public:
    ListNode* head=NULL;

    void addNode(int val){
        if(head==NULL){
            ListNode* node = new ListNode(val);
            head =node;
        }else{
            ListNode* cursor = head;
            while(cursor->next!=NULL){
                cursor = cursor->next;
            }
            
            ListNode* node = new ListNode(val);
            cursor->next = node;
        }
    }
    
    void addNode(ListNode* existingNode){
        if(existingNode==NULL){
            return;
        }else{
            if(head==NULL){
                ListNode* node = existingNode;
                head = node;
            }else{
            
                ListNode* cursor = head;
                while(cursor->next!=NULL){
                    cursor = cursor->next;
                }
                
                ListNode* node =  existingNode;
                cursor->next = node;
            }
        }
    }
    
    void printList(){
        if(head==NULL){
            cout<<"No nodes"<<endl;
        }else{
            ListNode* cursor = head;
            
            while(cursor!=NULL){
                cout<<cursor->key<<" -> ";
                cursor=cursor->next;
            }
        }
        cout<<endl;
    }
    
    
    ListNode* findNode(int searchKey){
        if(head==NULL){
            return NULL;
        }else{
            ListNode* cursor = head;
            
            while(cursor!=NULL && cursor->key !=searchKey){
                cursor=cursor->next;
            }
            
            if(cursor->key ==searchKey){
                return cursor;
            }else
                return NULL;
        }
    }
    
};


bool checkSameNode(ListNode* node1, ListNode* node2){
    if(node1 == node2)
        return true;
    
    return false;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
    
    //error check
    if(headA == NULL || headB == NULL) return NULL;

    
    ListNode* lastNode1 = headA;
    ListNode* lastNode2 = headB;
    int size1=1, size2=1;
    
    //check if the last nodes are the same
    while(lastNode1->next!=NULL){
        lastNode1 = lastNode1->next;
        size1++;
    }
    while(lastNode2->next!=NULL){
        lastNode2= lastNode2->next;
        size2++;
    }
    if(!checkSameNode(lastNode1, lastNode2))
        return NULL;
    
    
    
    //if the last nodes are the same, look for the intersection node
    
    ListNode* cur1 = headA;
    ListNode* cur2 = headB;
    int i=0;
    
    if(size1>size2){
        int diff = size1-size2;
        for(i=0; i<diff; i++){
            cur1 = cur1->next;
        }
        
        
        
    }else if(size2>size1){
        int diff = size2-size1;
        for(i=0; i<diff; i++){
            cur2 = cur2->next;
        }
    }
    
    while(!checkSameNode(cur1,cur2) && (cur1!=NULL && cur2!=NULL)){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

int main(){
    
    
    
    linkedList firstList, secondList;
    firstList.addNode(1);
    firstList.addNode(3);
    firstList.addNode(5);
    firstList.addNode(7);

    ListNode* intersectionNode = firstList.findNode(7); //이렇게 찾은 다음에
    
    secondList.addNode(9);
    secondList.addNode(intersectionNode);

    firstList.addNode(6);
    firstList.addNode(4);
    
    
    cout<<"list"<<endl;
    
    firstList.printList();
    secondList.printList();

    ListNode* output = getIntersectionNode(firstList.head, secondList.head); //.head를 통해 linked list의 listNode를 부를수 있다
    

    cout<<output->key;
}

