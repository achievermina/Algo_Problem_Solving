#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
void backtracking(string s, string current, vector<string> &res, int start, int digit, int size){
    if(digit==4){ ///digit should be 3!!
        if(size-start>3 ||size-start<1)
        return;
        else{
            string temp =s.substr(start, size-start);
            if((temp[0]!='0'|| temp=="0") && stoi(temp)<=255){
                current +=temp;
                res.push_back(current);
            }
            return;
            
        }
    }else if(size-start<1) //when it is not the last
    return;
    
    //addnumber
    for(int i =1 ; i<=3; i++){
        
        string temp =s.substr(start, i);
        if(temp[0]=='0' && temp!="0") return;
        
        int number =stoi(temp);
        if(number>255) return;
        
        current +=s.substr(start, i);
        current +=".";
        
        start = start+i;
        digit++;
        
        backtracking(s, current, res, start, digit, size);
        
        current = current.substr(0,start+digit-i-2);
        digit--;
        start=start-i;
    }
    
    //return res;
    
}

vector<string> restoreIpAddresses(string s) {
    int size = s.size();
    int digit =1;
    vector<string> res;
    string current ="";
    
    
    if(s.size()<4 || s.size()>12 ){
        return res;
    }
    
    backtracking(s, current, res, 0, digit,size);
    
    return res;
    
    
}
int main(){
    string s = "222222";
    restoreIpAddresses(s);
}
