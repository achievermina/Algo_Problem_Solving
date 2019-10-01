//
//  wayfair_balloon.cpp
//  algo
//
//  Created by Mina on 22/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//


#include<iostream>
#include<vector>
using namespace std;


string balloon(string s){
    vector<int> balloon(26,0), input(26,0);
    string target = "BALLOON";
    string res="", curS =s;
    bool flag=true;
    
    if(s.size()<7)
        return s;
    
    for(auto c:target) balloon[c-'A']++;
    for(auto c:s) input[c-'A']++;
    
    while(flag){
        //check if balloon
        for(auto c:target){
            if(input[c-'A']<balloon[c-'A']){
                flag=false;
                res=curS;
                break;
            }
        }
        
        //remove balloon
        if(flag){
            res ="";
            vector<int> temp =balloon;
            for(auto c:curS){
                if(temp[c-'A']>0){
                    temp[c-'A']--;
                    input[c-'A']--;
                }else{
                    res+=c;
                }
            }
        }
        curS=res;
        
            
    }
    return res;
    
}

int main(){
    cout<<balloon("BAONXXOLL")<<endl;
    cout<<balloon("BAOOLLNNOLOLGBAX")<<endl;
    cout<<balloon("QAWABAWONL")<<endl;

}
