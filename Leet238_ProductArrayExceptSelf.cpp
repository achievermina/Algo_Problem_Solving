//
//  Leet238_ProductArrayExceptSelf.cpp
//  algo
//
//  Created by Mina on 12/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


///NEW METHOD
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output( nums.size(), 1);
        int p=1;
        
        for(int i=0; i<nums.size(); i++){
            output[i]=p*output[i];
            p=nums[i]*p;
        }
        p=1;
        
        for(int i=nums.size()-1; i>=0; i--){
            output[i]=p*output[i];
            p=nums[i]*p;
        }
        
        return output;
    }
};

//FIRST SOLUTION --Need to find the faster solution

vector<int> productExceptSelf(vector<int>& nums) {
    //DIvision
    //         //multiplying all
    //         int multiply;
    //         for(int i=0; i<nums.size(); i++){
    //             multiply *=nums[i];
    //         }
    //         //get all value by dividing
    
    int multiply=1;
    queue<int> checkZero;
    vector<int> outputArr;
    
    //check if 0
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0)
            checkZero.push(i);
    }
    
    if(checkZero.size()==0){
        
        for(int i=1; i<nums.size(); i++){
            multiply *=nums[i];
        }
        
        outputArr.push_back(multiply);
        
        for(int i=1; i<nums.size(); i++){
            int answer= outputArr[i-1]*nums[i-1]/nums[i];
            outputArr.push_back(answer);
        }
        
        
    }else if(checkZero.size()<2){
        //calculate the multiply
        for(int i=0; i<nums.size(); i++){
            if(checkZero.front() ==i){
                checkZero.pop();
            }else
                multiply *=nums[i];
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                outputArr.push_back(multiply);
            else
                outputArr.push_back(0);
            
        }
        
    }else{
        for(int i=0; i<nums.size(); i++){
            outputArr.push_back(0);
        }
    }
    return outputArr;
    
}

