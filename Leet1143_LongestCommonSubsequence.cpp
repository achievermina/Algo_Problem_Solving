//
//  Leet1143_SCS.cpp
//  algo
//
//  Created by Mina on 04/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 string text1 = "pmjghexybyrgzczy";
string text2 = "hafcdqbgncrcbihkd";
 CASE when there is a repetition of the same alphabet...
 
*/

int longestCommonSubsequence(string text1, string text2) {
    
    int size1 = text1.size();
    int size2 = text2.size();
    
    int mem[size1+1][size2+1];
    for(int i =0; i<=size1; i++){
        for(int j=0; j<=size2; j++){
            if(i==0 || j==0 ){
                mem[i][j] = 0;
            }else if(text1[i-1] == text2[j-1])
                mem[i][j]=mem[i][j-1]+1;
            else
                mem[i][j]= max(mem[i-1][j], mem[i][j-1]);
            
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return mem[text1.size()][text2.size()];
    
}

int main(){

    string text1 = "pmjghexybyrgzczy";
    string text2 = "hafcdqbgncrcbihkd";
    cout<<longestCommonSubsequence(text1,text2);
}
