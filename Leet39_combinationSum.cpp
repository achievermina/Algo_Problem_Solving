//
//  Leet39_combinationSum.cpp
//  algo
//
//  Created by Mina on 26/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    
    sort(candidates.begin(), candidates.end());
    tracking(candidates,target, temp, res, 0, 0);
    
    return res;
}

void tracking(vector<int>& candidates, int target, vector<int> temp, vector<vector<int>>& res, int sum, int index){
    if(sum==target){
        // sort(temp.begin(), temp.end());
        // if(find(res.begin(), res.end(), temp)==res.end())
        res.push_back(temp);
        return;
    }
    
    for(int i =index; i<candidates.size(); i++){
        int c= candidates[i];
        if(sum+c<=target){
            temp.push_back(c);
            sum+=c;
            tracking(candidates, target, temp, res, sum, i); // i를 i+1이 아니기때문에 같은 숫자도 계속 들어갈수 있다.
            sum-=c;
            temp.pop_back();
        }
        
    }
    
    
