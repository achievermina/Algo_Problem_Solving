//
//  CTCI_DP_coins.cpp
//  graph_dfs
//
//  Created by Mina on 26/06/2019.
//  Copyright © 2019 Mina. All rights reserved.
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int coins(int n){
    int coin[4] = {1,5,10,25};
    int mem[n+1][4];
    
    for(int i =1; i<=n; i++) mem[i][0] = 1;
    for(int j=0; j<4; j++) mem[0][j] =1; // when money is 0 -> set 0? but 1 is right for calculations
        
    for(int i =1; i<=n; i++){
        for(int j=1; j<4; j++){
            if(i>=coin[j])
                mem[i][j]=mem[i-coin[j]][j] +mem[i][j-1];
            else
                mem[i][j]=mem[i][j-1];

        }
    }
    return mem[n][3];
}



int main(){
    cout<<"The numberof ways of representing n cents is "<<coins(10)<<endl;
    
}
