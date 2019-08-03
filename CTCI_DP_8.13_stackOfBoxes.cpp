//
//  CTCI_DP_8.cpp
//  algo
//
//  Created by Mina on 03/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define BOX_MAX 10;

struct box{
    int w, d, h;
    
    box(int init_w, int init_d, int init_h): w(init_w), d(init_d), h(init_h){};
           
};


int getHeight(int mem[], vector<box> boxArr, int num){
    
    int localMax = boxArr[num]->h;
    

    for(int i=0; i<num-1; i++){
        if((localMax<(mem[i]+boxArr[num]->h))&&(boxArr[num]->w >boxArr[i]->w)&&(boxArr[num]->h >boxArr[i]->h))
            localMax = mem[i];
    }
    return localMax;
    
}




int boxHeight(vector<box> boxArr){
    

    sort(boxArr.begin(), boxArr.end());
    
    int mem[BOX_MAX] = {-1};

    for(int i =0; i<boxArr.size(); i++){
        if(mem[i]==-1)
            mem[i] = getHeight(mem, boxarr, i);
    }
    
    return max_element(mem);
}


int main(){
    vector<*box> boxArr;
    
    
}
