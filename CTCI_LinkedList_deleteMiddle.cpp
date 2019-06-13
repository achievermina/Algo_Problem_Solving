//
//  CTCI_LinkedList_deleteMiddle.cpp
//
//Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
//EXAMPLE
//lnput:the node c from the linked lista->b->c->d->e->f
//Result: nothing is returned, but the new linked list looks like a->b->d->e- >f

#include <iostream>
#include <string>
using namespace std;

class Node{
 
    
public:
    char key;
    Node* next;
    
    
    Node(char key){
        this->key = key;
        this->next =NULL;
    }
};


class linkedList{
    Node* head=NULL;
    
public:
    void addNode(char key){
        if(head==NULL){
            Node* node = new Node(key);
            head =node;
        }else{
            Node* cursor = head;
            while(cursor->next!=NULL){
                cursor = cursor->next;
            }
            
            Node* node = new Node(key);
            cursor->next = node;
        }
    }
    
    Node* findPrev(char key){
        Node* cursor = this->head;
        Node* prev = NULL;

        while(cursor!=NULL){
            if(cursor->key==key)
                return prev;
            
            prev=cursor;
            cursor=cursor->next;
        }
        
      
        return NULL;
        
    }
    
    void deleteNode(char key){
        Node* targetPrev = findPrev(key);
        Node* target = targetPrev->next;
        if(targetPrev!=NULL){
            targetPrev->next = target->next;
            target->next=NULL;
            delete target;
            
        }else{
            cout<<"cannot find the target"<<endl;
        }
    }
    
    void printList(){
        if(head==NULL){
            cout<<"No nodes"<<endl;
        }else{
            Node* cursor = head;
            while(cursor!=NULL){
                cout<<cursor->key<<" -> ";
                cursor=cursor->next;
            }
        }
    }
};


int main(){
    linkedList firstList;
    firstList.addNode('a');
    firstList.addNode('b');
    firstList.addNode('c');
    firstList.addNode('d');
    firstList.addNode('e');
    firstList.addNode('f');
    cout<<"list"<<endl;
    firstList.printList();

    cout<<""<<endl;
    cout<<"after remove c"<<endl;

    firstList.deleteNode('c');
    firstList.printList();

    
    


}
