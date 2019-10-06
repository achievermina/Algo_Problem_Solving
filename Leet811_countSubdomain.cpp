//
//  Leet811_countSubdomain.cpp
//  algo
//
//  Created by Mina on 04/10/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
vector<string> subdomainVisits(vector<string>& cpdomains) {
    map<string, long> countMap;
    vector<string> res;
    for(auto domain:cpdomains){
        //find the number
        int idx = domain.find(" ");
        int n = stoi(domain.substr(0,idx));
        string subdomain = domain.substr(idx, domain.size());
        string sub;
        
        int prev=0;
        int current = 0;
        while(current!=string::npos){ // 차라리 이거말고... 하나하나돌면서 if("." 찾는게 빠를수도!!!!)
            sub= subdomain.substr(current+1,subdomain.size()-current);
            prev=current+1;
            countMap[sub]+=n;
            sub.clear();
            current = subdomain.find(".", prev);
        }
    }
    
    map<string, long>::iterator it;
    string word;
    for(it=countMap.begin(); it!=countMap.end(); it++){
        word+=to_string(it->second);
        word+=" ";
        word+=(it->first);
        res.push_back(word);
        word.clear();
    }
    
    
    return res;
    
}


int main(){
    vector<string> vec ={"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    subdomainVisits(vec);
}

