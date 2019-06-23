//
//  CTCI_DP_Fibonacci.cpp
//
//  Created by Mina on 21/06/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int memoization(int i, int mem[]){
    if(i==2 or i==1){
        mem[i]=1;
    }
    
    if(mem[i]==0)
        mem[i]=memoization(i-1, mem)+memoization(i-2,mem);
    
    return mem[i];
    
}

int fibonacci(int i, int mem[]){
    
    if(i<0)
        return -1;
    
    return memoization(i, mem);
}


int main(){
    int mem[1000]= {0};
    
    cout<<fibonacci(4, mem);
}
