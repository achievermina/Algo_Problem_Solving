#include<iostream>
using namespace std;


bool match(const string& w, const string& s){

    int pos=0;
    //check w[pos] and s[pos]
    while(pos <s.size() && pos<w.size() && (w[pos]=='?'||w[pos]==s[pos])){
        ++pos;
    }
    //after while loop
    if(pos== w.size())
        return pos =s.size(); //if s is also done match is TRUE, otherwise FALSE

    if(w[pos]=='w'){
        for(int skip =0; pos+skip <=s.size(); ++skip){
            if(match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
        }
    }

    //False if none of the above cases
    return false;

}

int main(){
    string a,b;

    cin>>a>>b;
    cout<<"The word "<<a<<" and "<<b<<" are mathced?\n"<<match(a,b)<<endl;

}