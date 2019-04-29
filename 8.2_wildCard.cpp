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

//String is max 100
int cache[101][101] ={-1};
string W,S;

//Big O(n^3)
int matchMemoized(int w, int s){
    int& ret =cache[w][s];

    if(ret != -1)
        return ret;

    while(s<S.size() && w<W.size() && (W[w]=='?' || W[w] ==S[s])){
        ++w;
        ++s;
    }

    //after while loop
    //check how many alphabets matching to *
    if(W[w]=='*')
        for(int skip =0; skip+s <=S.size(); ++skip){
            if(matchMemoized(w+1, s+skip))
                return ret=1;
        }

    return ret = 0;
}

int main(){
    string a,b;

    cin>>a>>b;
    cout<<"The word "<<a<<" and "<<b<<" are matched?\n"<<match(a,b)<<endl;



    cout<<"The word "<<a<<" and "<<b<<" are matched?\n"<<matchMemoized(0,0)<<endl;


}