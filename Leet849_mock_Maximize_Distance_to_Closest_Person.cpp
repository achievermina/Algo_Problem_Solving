//
//  Leet849_mock_Maximize_Distance_to_Closest_Person.cpp
//  algo
//
//  Created by Mina on 29/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
/*
 
 In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.
 
 There is at least one empty seat, and at least one person sitting.
 
 Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 
 Return that maximum distance to closest person.
 
 Example 1:
 
 Input: [1,0,0,0,1,0,1]
 Output: 2
 Explanation:
 If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 If Alex sits in any other open seat, the closest person has distance 1.
 Thus, the maximum distance to the closest person is 2.
 Example 2:
 
 Input: [1,0,0,0]
 Output: 3
 Explanation:
 If Alex sits in the last seat, the closest person is 3 seats away.
 This is the maximum distance possible, so the answer is 3.
 
 */

#include <stdio.h>

//For the cases, when the first or last seat is an empth set, I could have separate for loop instead of adding those cases in the current for loop
//I should have count the answer(number of closest person), not zeros
//[0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1] in this case, it is hard to split another case.

int maxDistToClosest(vector<int>& seats){
    int maxStart=-1, maxIdx=0, maxCount=0, zeroCount=0;
    
    for(int i =0; i<seats.size(); i++){
        if(seats[i]==0){
            zeroCount++;
            
            if(maxStart ==-1)
                maxStart = i;
            
        }else if(zeroCount!=0){
            if(zeroCount>maxCount){
                maxStart = i-zeroCount;
                if(maxStart ==0 && zeroCount!=1)
                    maxCount = zeroCount+1;
                else{
                    maxCount = zeroCount;
                    maxIdx = i-1;
                }
            }
            
            zeroCount = 0;
            
        }
        
    
        //when the last zeros are the max
        if(i==seats.size()-1 && seats[i]==0 && zeroCount!=1 && (zeroCount>=maxCount))
            return zeroCount;
        
    }
    
    if(maxStart==0 && maxCount!=1)
        return maxCount;
    
    if(maxCount == 1)
        return 1;
    else
        return ceil(maxCount/2.0);
    
    
    
    }
