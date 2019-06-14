//
//  CTCI_Stack_stackofPlates.cpp
//  graph_dfs
//
//  Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
//composed of several stacks and should create a new stack once the previous one exceeds capacity.
//Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
//SetOfStacks.push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).
//FOLLOW UP
//ImplementafunctionpopAt(int index)whichperformsapopoperationonaspecificsub-stack.
//


//stack syntax
#include <iostream>
#include <string>
#include <stack>
using namespace std;

DEFINE SIZE = 10;

class Stack{
    int count;
    
    Stack(){
        
    }
    
    
    bool checkSize(){
        if(count>=SIZE){
            return false;
        }
        return true;
        
    }
    
    int popAt(int index){
        
    }
    
    int push(){
        if(checkSize()){
            
        }
        
    }
};

