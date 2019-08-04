//
//  9.cpp
//  algo
//
//  Created by Mina on 03/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int maxNeed(int capacity, int NumofItem, vector<int> weight, vector<int> need){
    int mem[capacity+1][NumofItem+1];
    
    for(int i=0; i<=capacity; i++){
        for(int j=0; j<=NumofItem; j++){
            if(i==0 || j==0) mem[i][j]=0;
            else if(weight[j]> capacity) mem[i][j] = mem[i][j-1];
            else
                mem[i][j] = max(mem[(i-weight[j])][j-1]+need[j],mem[i][j-1]);
        }
    }
    return mem[capacity][NumofItem];
}
