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

class SetOfStacks{
public:
    int countElements;
    int stackIdx;
    //vector of pointers
    vector<stack<int>*> stackArr;

    
    SetOfStacks(){
        stackIdx =0;
        countElements =0;
        stack<int>* s = new stack<int>; //dynamic allocation
        (stackArr).push_back(s);
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
            stack<int>* sNew = createNewStack();
            sNew->push(value); //pointer uses ->
        }
        countElements++;
        cout<<"pushed value of "<<value<<endl;
        cout<<"stack number "<<stackIdx+1<<endl;
    }
    
    stack<int>* createNewStack(){
        stack<int>* newS =new stack<int>;
        stackIdx++;
        //stackArr[stackIdx] = newS; // 이렇게 assign하면 안되고 push_back해야돼
        stackArr.push_back(newS);
        return newS;
    }
    
    void pop(){
        //stack<int> currentStack = *stackArr[stackIdx]; // wrong version. 이렇게 하면 함수 안에서만 바뀌고 밖에는 안됨
        stack<int>* currentStack = stackArr[stackIdx]; //bring the stack using pointer and modify the original one

        int value = currentStack->top();
        currentStack->pop();
        countElements--;
        cout<<"popped value of "<<value<<endl;
        cout<<"stack number "<<stackIdx+1<<endl;
        
        if(currentStack->empty()){ //For push we check the size, so we shouldn't have any empty stack
            stackIdx --;
            delete currentStack;
            cout<<"stack  "<<stackIdx+2<<" is deleted"<<endl;;
        }

    }
    
    
    void popAt(int index){
        //error
        if(index-1>stackIdx){
            cout<<"Error! Check with the index"<<endl;
        }else{
            stack<int>* currentStack = stackArr[(index-1)];
            cout<<"popped value of "<<currentStack->top()<<" at the stack of "<<index<<endl;
            currentStack->pop();
            
            if(currentStack->empty()){
                stackIdx--;
                delete currentStack;
                cout<<"stack  "<<stackIdx+2<<" is deleted"<<endl;;

            }
            
        }
    }
    

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
    haha.pop();
    haha.pop();
    haha.pop();

    haha.push(8);
    haha.push(9);
    haha.push(10);
    
    haha.popAt(1);

    
    
}

