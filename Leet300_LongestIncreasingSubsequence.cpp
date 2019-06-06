/*
Leetcode300 Longest Increasing Subsequence
6/5/19

vector[i]=0; is not working
Math.max(a,b)
dp[0] =1;  Only first is needed to define.

*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> longestArr;
        for(int i = 0; i<n; i++){
            longestArr.push_back(0);
        }
        
        
        for(int i=0; i<n; i++){
            int max=1;
            
            for(int j=0; j<i; j++){
                if((nums[j]<nums[i]) && (max<1+longestArr[j])){
                    max = 1+longestArr[j];
                }
                
            }
            
            longestArr[i] = max;
        }

        int longest=0;
        for(int i=0; i<n; i++ ){
            if(longest< longestArr[i]){
                longest = longestArr[i];
            }
        }
        
        return longest;
        
    }
};