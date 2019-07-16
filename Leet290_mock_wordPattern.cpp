//
//  Leet_uber_wordPattern.cpp
//  algo
//
//  Created by Mina on 14/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
/*
 Given a pattern and a string str, find if str follows the same pattern.
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 
 Example 1:
 
 Input: pattern = "abba", str = "dog cat cat dog"
 Output: true
 Example 2:
 
 Input:pattern = "abba", str = "dog cat cat fish"
 Output: false
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

//string space 띄는방법
//map 빨리 사용하는 방법
/*
 "abba"
 "dog dog dog dog"
 
 true
 */
//이걸 통과하려면 value가 중복인것도 찾아내야하네!!!!!!!!!


bool wordPattern(string pattern, string str) {
    
    if(pattern.size()==0 || str.size() == 0) return false;

    int patternSize = pattern.size();
    int patternArr[patternSize];
    string strArr[patternSize+5];
    
    //get pattern
    for(int i =0; i<patternSize; i++){
        patternArr[i] = pattern[i]-'a';
    }
    
    //get words
    for(int len=0, idx =0, start =0, j =0; j<=str.size(); j++, len++){
        
        if(str[j]==' ' || j==str.size()){
            //substr(start, lenth)
            
            strArr[idx]=str.substr(start, len);
            len=-1;
            start =j+1;
            idx++;

        }
    }
    
//    if(sizeof(patternArr)/sizeof(int)!=sizeof(strArr)/sizeof(string))
//        return false;
//
    //create a hash map with pair
    map<int, string> table;
    
    for(int i =0; i<patternSize; i++){
        if(!table.count(patternArr[i]))
            table.insert(pair<int,string>(patternArr[i],strArr[i]));
        
        else{
            string word = strArr[i];
            string patternWord = table[patternArr[i]];
            
            if(word.compare(patternWord)!=0)
                return false;
        }
    }
    return true;
    

        
}

int main(){

    
    string pattern= "aba";
    string sr =    "cat cat cat dog";
    
    wordPattern(pattern, sr);
}



