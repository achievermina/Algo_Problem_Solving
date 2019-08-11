//
//  Leet_mock_0000.cpp
//  algo
//
//  Created by Mina on 10/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
#include <queue>
#include <vector>
using namespace std;

class MovingAverage {
    
    int movingSize;
    int currentSum;
    int currentSize;
    queue<int> current;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        movingSize = size;
        currentSum = 0;
        currentSize= 0;
    }
    
    
    
    double next(int val) {
        if(current.empty() || currentSize<movingSize){
            current.push(val);
            currentSum+=val;
            currentSize++;
        }else{
            int oldNum = current.front();
            currentSum -=oldNum;
            current.pop();
            current.push(val);
            currentSum +=val;
        }
        
        return currentSum/(double) currentSize;
        
    }
    
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */


int main(){
    MovingAverage m = MovingAverage(3);
    cout<<m.next(1);
    cout<<m.next(10);
    cout<<m.next(3);
    cout<<m.next(5);
}
