//
//  CTCI_array_checkPermutation.cpp
//

#include <iostream>
#include <string>
using namespace std;

bool checkPermutation(string a, string b){
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
//    for(int i =0; i<sortedA.size(); i++){
//        if(sortedA[i] !=sortedB[i])
//            return false;
//    }
    
    //use compare function
    if(a.compare(b))
        return true;
    else
        return false;

}


int main(){
    string a="mina";
    string b="ainm";
    cout<<checkPermutation(a,b)<<endl;
    
}
