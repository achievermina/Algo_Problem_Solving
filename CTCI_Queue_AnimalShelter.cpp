//
//  CTCI_Queue_AnimalShelter.cpp
//
//  CTCI_Stack_Stckmin.cpp
//
// Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the"oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked list data structure.

#include <iostream>
#include <list>
#include <stack>
using namespace std;


enum Animal {dog, cat, any};


//using list in c++
class Node{
public:
    int id;
    
    Node(int inputId){
        id =inputId;
    }
};

class AnimalQueue{
private:
    
    list<Node> dogqueue;
    list<Node> catqueue;
    
    int id;
    
public:
    
    //constructor
    AnimalQueue(){
        id=0;
    }
    
    void enqueue(Animal typeofanimal){
        
        list<Node>* currentQ;
        
        switch (typeofanimal) {
            case dog:
                currentQ = &dogqueue;
                break;
                
            case cat:
                currentQ = &catqueue;
                break;
                
            default:
                cout<<"Need to define the animal type"<<endl;
                return (void)"Doesn't Print";
        }
        
        
        currentQ->push_back(id);
        cout<<"id "<<currentQ->back().id<<" "<<typeofanimal<<" has protected in the shelter"<<endl;
        id++;
        
        
    }
    
    void dequeue(Animal typeofanimal=any){
        
        list<Node>* currentQ;
        
        switch (typeofanimal) {
            case dog:
                currentQ = &dogqueue;
                break;
                
            case cat:
                currentQ = &catqueue;
                break;
                
            default:
                if(dogqueue.size()>catqueue.size())
                    currentQ = &dogqueue;
                else
                    currentQ = &catqueue;
        }
        
        cout<<"id "<<currentQ->front().id<<" "<<" has adopted"<<endl; // 이거어떻게 보이게 하나요
        currentQ->pop_front();
        
    }
        
        
    
    
    void printQueue(list<Node> cc){
        
//        for(list<Node>::iterator it =cc.begin(); it!=cc.end(); it++){
//            cout<<(*it)<<endl;
//        }
    }
    
    
    
    
};

int main(){
    
    AnimalQueue q;
    q.enqueue(dog);
    q.enqueue(dog);
    q.enqueue(cat);
    q.enqueue(cat);
    q.enqueue(dog);
    q.enqueue(dog);
    q.enqueue(dog);
    
    q.dequeue(dog);
    q.dequeue(cat);
    q.dequeue();
    
    

}

