//
//  DP_rodCutting.cpp
//
//  Created by Mina on 24/06/2019.

#include <iostream>
#include <cmath>
#include <array>
using namespace std;




int highestPrice(int price[], int arrSize){
    int mem[arrSize+1];
    int q;
    
    for(int i=0; i<arrSize+1; i++){
        mem[i]=INT_MIN;
    }
    mem[0] = 0;

    // fill up mem
    for(int i=1; i<arrSize+1; i++){
        for(int j =0; j<i; j++){
            q = max(q, price[i-j-1]+mem[j]);
        }
        mem[i]= q;
    }
    
    return mem[arrSize];
}





int main(){
    int price[10] = {1,5,8,9,10,17,17,20,24,30};
    
    cout<<highestPrice(price, 10);
}
