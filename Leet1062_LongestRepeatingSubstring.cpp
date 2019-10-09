//
//  Leet1062_LongestRepeatingSubstring.cpp
//  algo
//
//  Created by Mina on 06/10/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
///using DP O(N^2)
int longestRepeatingSubstring(string S) {
    
    int N = S.size();
    vector<vector<int>> DP(N+1, vector<int>(N+1,0));
    int maxCount = 0;
    
    for(int i =1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(S[i-1]==S[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
                maxCount = max(maxCount,DP[i][j]);
            }
        }
    }
    return maxCount;
    
    
    
    
    
    
}


// //Brute Force method using find function O(N^3) --worst

//     int longestRepeatingSubstring(string S) {
//         int maxCount=0;
//         for(int i =0; i<S.size(); i++){
//             char curWord = S[i];
//             int curIdx =i, prevIdx=i;

//             while(S.find(curWord, prevIdx+1)!=string::npos){
//                 int count=1;
//                 int idx1 = curIdx;
//                 int idx2=S.find(curWord, prevIdx+1);
//                 prevIdx = idx2;
//                 while(S[idx1+1]==S[idx2+1]){
//                     idx1++; idx2++;
//                     count++;
//                 }
//                 maxCount= max(maxCount, count);
//             }
//         }
//         return maxCount;

//     }

int main(){
    string S = "abbaba";
    cout<<longestRepeatingSubstring(S);
}
