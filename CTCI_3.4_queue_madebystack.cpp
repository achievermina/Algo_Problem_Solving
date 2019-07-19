//
//  CTCI_3.cpp
//  algo
//
//  Created by Mina on 19/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


class myqueue{
private:
    stack<int> oldest, newest;

public:
    void push(int value){
        oldest.push(value);
        
    }
    
    void pop(){
        if(newest.empty()){
            if(oldest.empty())
                terminate();
            
            while(!oldest.empty()){
                newest.push(oldest.top());
                oldest.pop();
            }
            
        }
        
        cout<<newest.top()<<endl;
        newest.pop();
    }

    
};


int main(){
    myqueue q;
    q.push(1);
    q.push(3);
    q.push(5);
    q.pop();
    
}
