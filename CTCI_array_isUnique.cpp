//
//  CTCI_array_isUnique.cpp
//
//  array initialization = {0 };
//  Created by Mina on 11/06/2019.


#include <iostream>
#include <string>
using namespace std;

bool isUnique(string word){
    int array[128]={0};
    
    for(int i=0; i<word.size(); i++){
        int idx = word[i]%128;
        array[idx]++;
        if(array[idx]>=2){
            return false;
        }
    }
    return true;
}


int main(){
    bool result = isUnique("onetw");
    if(!result){
        cout<<"not unique"<<endl;
    }else{
        cout<<"unique"<<endl;
    }
    
    cout<<isUnique("hello")<<endl;
    cout<<isUnique("mina")<<endl;

}
