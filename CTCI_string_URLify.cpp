//
//Add %20 to space
//

#include <iostream>
#include <string>
using namespace std;

string URLify(string word, int size){
    string str2 = "%20";
    for(int i=0; i<size; i++){
        if(word[i]==' '){
            word.replace(i,1,str2);
        }
        
    }
    return word;
}


int main(){
    string a="Mr John Smith ";
    int b = 13;
    cout<<URLify(a,b)<<endl;
    
}
