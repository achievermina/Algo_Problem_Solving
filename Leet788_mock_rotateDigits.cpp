//
//  Leet788_mock_rotateDigits.cpp
//  algo
//
//  Created by Mina on 29/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

/*
 X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.
 
 A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
 
 Now given a positive number N, how many numbers X from 1 to N are good?
 
 Example:
 Input: 10
 Output: 4
 Explanation:
 There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 Note:
 
 N  will be in range [1, 10000].
 

 */

//TRY DP METHOD






//First I didn't know I can solve it as a string. COUNT THE NUMBER seems like I ned to solve math problems.
//Using BruteForce - string.
//Or I can use while loop in checkGood to make num/10 and not using string
#include <iostream>
#include <string>

using namespace std;


bool checkGood(string Ntostring){
    int count=0;
    
    for(int j =0 ; j< Ntostring.size(); j++){
        int checkNumber = (int) (Ntostring[j]) -48;
        if(checkNumber==3 ||checkNumber==4||checkNumber==7) return false;
        else if(checkNumber==2||checkNumber==5||checkNumber==6||checkNumber==9) count++;
    }
    
    if(count>0) return true;
    else return false;
}


int rotatedDigits(int N) {
    int goodN=0;
    
    for(int i =1; i<=N; ++i){
        string numberString = to_string(i);
        if(checkGood(numberString)) goodN++;
        
    }
    
    return goodN;
}

int main(){
    cout<<rotatedDigits(10);
}



//
//
//
//int rotatedDigits(int N) {
//    if(N<=10){
//
//    }else{
//
//    }
//    //find the first digit
//
//
//}
//
//bool yesOrNo(int n){
//    vector<int> check = {0,1,2,5,6,8,9};
//
//    if(check.find(n)>=0)
//        return true;
//    else
//        return false;
//    }
