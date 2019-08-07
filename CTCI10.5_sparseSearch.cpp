//
//
//  Created by Mina on 07/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int sparseSearch(vector<string> strArr, string word){
    int count =0;
    for(int i =0; i<strArr.size(); i++){
        if(strArr[i]=="")
            count++;
        else if(word.compare(strArr[i])==1)
            count++;
        else
            return count;
    }
    
    return -1;
}


int main(){
    vector<string> vec ={ "at",  "", "","","", "ball", "car","", "dad"};
    string w = "ball";
    cout<<sparseSearch(vec,w);
}
