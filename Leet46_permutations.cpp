//
//  Leet46_permutations.cpp
//  algo
//
//  Created by Mina on 22/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
#include <iostream>
#include <vector>
using namespace std;




void recursive(vector<vector<int>>& output, vector<int> nums, vector<int> perm){
    if(nums.size()==0){
        output.push_back(perm);
        return;
    }
    
    for(int i =0; i<nums.size(); i++){
        perm.push_back(nums[i]);
        nums.pop_back();
        
        recursive(output, nums, perm);
        
        nums.push_back(nums[i]);
        perm.pop_back();

    }
  
}
vector<vector<int>> permute(vector<int>& nums) {
    // if(nums.size()==0)
    //     return;
    
    vector<vector<int>> output;
    vector<int> perm;
    
    recursive(output, nums, perm);
    
    return output;
    
}
int main(){
    vector<int> list = {1,2,3};
    permute(list);
}



