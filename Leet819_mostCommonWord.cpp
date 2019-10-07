//
//  Leet819_mostCommonWord.cpp
//  algo
//
//  Created by Mina on 06/10/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> countMap;
    
    string res;
    int maxCount=0;
    
    //이런생각을 어떻게 해내지
    for(auto &c:paragraph){
        if(isalpha(c))
            c=tolower(c);
        else
            c=' ';
    }
    
    char *cstr = &paragraph[0];
    char *word = strtok(cstr, ",.!? ");
    while(word!=NULL){
        countMap[word]++;
        word =strtok(NULL, ",.!? ");
    }
    
    for(auto s:banned) countMap[s]=-1;
    
    unordered_map<string, int>::iterator it;
    for(it=countMap.begin(); it!=countMap.end(); it++){
        if((it->second) > maxCount){
            maxCount=it->second;
            res=(it->first);
        }
    }
    return res;
}
