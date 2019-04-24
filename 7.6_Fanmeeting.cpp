#include<iostream>
using namespace std;


// a += b*10^k
void addTo(vector<int>& a, const vector<int>& b, int k){
    a.resize(b.size()+k);
    for(int i =0; i<b.size(); i++){
        a[i+k]+=b[i];
    }
    normalize(a);

}

void subFrom(vector<int>& a, const vector<int>& b){


}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size();
    int bn= b.size();

    if(an<bn)
        retrun karatsuba(b,a);

    //base case
    if(an == 0|| bn==0)
        return vecotr<int>();



    int half = an/2;


    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vecotr<int> b0(b.begin(), b.begin()+min<int>(b.size(0,half)));
    vector<int> b1(b.begin()++min<int>(b.size(0,half), b.end());


    vector<int> z1, z2, z0;

    z2 = karatsuba(a1, b1);
    z0 = karatsuba(a0,b0);
    addT0(a0, a1, 0);

//z1

}