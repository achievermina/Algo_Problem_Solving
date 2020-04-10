//
//  Leet239_slidingWindowMaximum.cpp
//  algo
//
//  Created by Mina on 08/10/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    
    for(int i=0; i<k; i++){
        while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    
    for(int i =k-1; i<nums.size(); i++){
        while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        
        res.push_back(nums[dq.front()]);
        if(dq.front()<=i-k+1) dq.pop_front();
        
    }
    
    return res;
    
    
}
