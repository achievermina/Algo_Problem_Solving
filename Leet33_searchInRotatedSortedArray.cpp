//
//  Leet33_searchInRotatedSortedArray.cpp
//  algo
//
//  Created by Mina on 07/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


///NEED TO CHECK START END"S MID OR MID+1
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//SECOND ATTEMPT -- debug 엄청났음

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        else if(nums.size()==1){
            if(  nums[0]==target)
                return 0;
            else
                return -1;
        }
        
        int start=0, end=nums.size()-1;
        return searchBS(start, end, nums, target,0);
    }
    
    int searchBS(int start, int end, vector<int> nums, int target, int index){
        int mid = floor((end+start)/2);
        
        if(end-start==0 && nums[mid]!=target)
            return -1;
        else if(nums[mid]==target)
            return mid;
        
        
        if(nums[start]<=nums[mid] && nums[mid]>=nums[end]){ //e.g) 4, 7, 3
            if(target>=nums[start] && target<=nums[mid])
                return searchBS(start,mid,nums,target,index);
            else if(target>=nums[mid] || target<=nums[end]){
                return searchBS(mid+1,end,nums,target,index+mid);
            }else
                return -1;
            
        }else if(nums[mid]<=nums[start] && nums[mid]<=nums[end]){//e.g) 7, 4, 6
            if(target>=nums[mid] && target<=nums[end])
                return searchBS(mid+1,end,nums,target,index+mid);
            else if(target>=nums[start] || target<=nums[mid]){
                return searchBS(start,mid,nums,target,index);
            }else
                return -1;
            
        }else{ //when in order e.g) 4,5,6
            if(target>nums[mid]){
                return searchBS(mid+1,end,nums,target,index+mid);
            }else{
                return searchBS(start,mid,nums,target,index);
            }
        }
        
    }
};

//int search(vector<int>& arr, int target) {
//    int start= 0, end =arr.size()-1;
//    while(start<=end){
//        int mid= (end-start)/2;
//
//        if(arr[mid] ==target)
//            return mid;
//        else if(arr[mid]>=arr[start]){
//            if(target<=arr[start] && target>arr[mid])
//                start = mid+1;
//            else end =mid;
//        }else if(target >arr[start]){
//            end =mid;
//        }else
//            start =mid;
//    }
//
//    return -1;
//}
//


//MINA's
//int search(vector<int>& arr, int target) {
//    int start= 0, end =arr.size()-1;
//    while(start<=end){
//        int mid= (end-start)/2;
//        
//        if(arr[mid] ==target)
//            return mid;
//        else{
//            if(arr[mid]>=arr[start]){
//                if(target<=arr[start])
//                    start = mid+1;
//                else if(target<arr[mid])
//                    end =mid;
//                else
//                    start =mid+1;
//                
//            }else if(target >arr[start]){
//                end = mid;
//            }else
//                start = mid;
//        }
//    }
//    
//    
//    return -1;
//}
