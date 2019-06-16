//
//  CTCI_Stack_stackofPlates.cpp
//  graph_dfs
//
//  Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
//composed of several stacks and should create a new stack once the previous one exceeds capacity.
//Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
//SetOfStacks.push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).
//FOLLOW UP
//Implement a function popAt(int index)whichperformsapopoperationonaspecificsub-stack.
//


//stack syntax
#include <iostream>
#include<vector>
#include <stack>
using namespace std;

#define STACKMAX 5
#define SETSIZE 100

class SetOfStacks{
public:
    int countElements;
    int stackIdx;
    //vector of pointers
    vector<stack<int>*> stackArr;
    
    SetOfStacks(){
        stackIdx =0;
        countElements =0;
        stack<int> s;
        (stackArr).push_back(&s);
    }
    
    bool checkEnoughSize(stack<int> currentStack){
        if(currentStack.size()>= STACKMAX){
            return false;
        }
        return true;
    }
    
    void push(int value){
        stack<int> currentStack = *stackArr[stackIdx];
        
        if(checkEnoughSize(currentStack)){
            (*(stackArr[stackIdx])).push(value);
        }else{
            stack<int> sNew = createNewStack();
            sNew.push(value);
        }
        countElements++;
        cout<<"pushed value of "<<value<<endl;
        cout<<"stack number "<<stackIdx+1<<endl;
    }
    
    stack<int> createNewStack(){
        stack<int> newS;
        stackIdx++;
        stackArr[stackIdx] = &newS;
        countElements =0;
        
        return newS;
    }
    
    void pop(){
        stack<int> currentStack = *stackArr[stackIdx];

        if(currentStack.empty()){
            stackIdx --;
            currentStack = *stackArr[stackIdx];
            cout<<"popped value of "<<currentStack.top()<<endl;
            currentStack.pop();
        }else{
            cout<<"popped value of "<<currentStack.top()<<endl;
            currentStack.pop();
        }
        
        cout<<"stack number "<<stackIdx+1<<endl;
    }
    
    
//    int popAt(int index){
//        pass;
//    }
    

};

int main(){
    SetOfStacks haha;
    haha.push(3);
    haha.push(4);
    haha.push(5);
    haha.push(6);
    haha.push(7);
    haha.push(8);
    haha.push(9);
    haha.push(10);

    haha.pop();
    
    
}

