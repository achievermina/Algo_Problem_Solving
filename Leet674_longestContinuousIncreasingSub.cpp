    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength =0;
        int currentMax=1;
        
        if(nums.size()<1)
            return 0;
        
        for(int i=1; i< nums.size(); i++){
            if(nums[i-1]<nums[i]){
                currentMax++;
                
            }else{
                maxLength = max(maxLength,currentMax);
                currentMax=1;
            }
        }
        maxLength = max(maxLength,currentMax);

        return maxLength;
            
    }
