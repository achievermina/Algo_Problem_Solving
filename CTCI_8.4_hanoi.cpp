//
//  CTCI_8.cpp
//  algo
//
//  Created by Mina on 19/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX_HANOI 30;

//0부터 주의하기
int arr[30];

int hanoi(int n){
    
    if(n==2)
        arr[1] = 3;
    else if(n==1)
        arr[0] = 1;
    
    
    if(arr[n-1]==0){
        arr[n-1] = 3*hanoi(n-1)+1;
    }
    
    
    return arr[n-1];
}


int main(){
    
  

    cout<<hanoi(5)<<endl;
}
