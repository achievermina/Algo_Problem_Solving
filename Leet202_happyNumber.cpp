//
//  Leet202_happyNumber.cpp
//  algo
//
//  Created by Mina on 25/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

//fast, slow--> cycle detection
class Solution {
public:
    bool isHappy(int n) {
        int fast= n, slow= n;
        
        do{
            fast= help(help(fast));
            slow= help(slow);
        }while((fast!=slow) && !(fast==1 || slow==1));
        
        if(fast==1||slow==1)
            return true;
        else
            return false;
        
    }
    
    int help(int k){
        int newNumber=0, num =k;
        while(num!=0){
            int digit = num%10;
            newNumber +=pow(digit, 2);
            num=num/10;
        }
        return newNumber;
    }
};
