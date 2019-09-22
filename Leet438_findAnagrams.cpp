//
//  Leet438_findAnagrams.cpp
//  algo
//
//  Created by Mina on 19/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
//Windowsliding

vector<int> findAnagrams(string s, string p) {
    vector<int> pmap(26,0), smap(26,0);
    vector<int> res;
    
    if(s.size()<p.size())
        return res;
    
    //map initialization
    for(int i=0; i<p.size(); i++){
        pmap[p[i]-'a']++;
        smap[s[i]-'a']++;
    }
    
    if(pmap==smap)
        res.push_back(0);
    
    int left=0, right=p.size()-1;
    while(right<s.size()-1){
        
        smap[s[left]-'a']--;
        left++; right++;
        smap[s[right]-'a']++;
        
        if(pmap==smap)
            res.push_back(left);
        
    }
    
    return res;
    
}

//FIRST ATTEMPT
//map 대신 어차피 알파벳이기 때문에 vector<int>를 통해서 0-26 숫자 채우고 단순히 vector 비교 했어도 됨
//벡터로 간단하게 되는건 앞으로도 그냥 vector로 하는게 맞는것 같다!
//슬라이딩 도어는 left-right 의 사이즈가 같은사이즈로 계속 된다는데 있다!


bool compareMaps(map<char,int> a, map<char,int> b){
    if(a.size()!=b.size())
        return false;
    
    map<char,int>::iterator i,j;
    for(i=a.begin(), j=b.begin(); i!=a.end(); i++, j++){
        if(*i!=*j)
            return false;
    }
    return true;
}


vector<int> findAnagrams(string s, string p) {
    
    int sizeP = p.size();
    int keep=1, left=0, right=1;
    vector<int> res;
    map<char,int> hashmap;
    map<char,int> hashmap2;
    
    
    for(auto c:p){
        if(hashmap.count(c)>0)
            hashmap[c]++;
        else
            hashmap[c]=1;
    }
    
    //이건 슬라이딩 윈도우가 아니라 그냥 그때그때 보는건데...사이즈를 같게 해야된다는 포인트를 놓친듯
    while(left<s.size() && right<s.size()){
        while(hashmap.count(s[left])<1) left++; //run to pass unuseful chars
        right = left+1;
        while(hashmap.count(s[right])>0) right++;
        if(right-left+1<sizeP){
            left=right;
        }else{
            for(int i=left; i<sizeP; i++){
                hashmap2[i]++;
            }
            if(compareMaps(hashmap,hashmap2))
                res.push_back(left);
            else
                left++;
        }
        hashmap2.clear();
    }
    return res;
    }
