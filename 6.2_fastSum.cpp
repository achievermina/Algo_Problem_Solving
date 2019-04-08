//
// Created by Mina on 08/04/2019.
//



#include <iostream>
using namespace std;


int fastSum(int n){
    if(n==1)
        return 1;


    return n+fastSum(n-1);

}




int main(){


    fastSum(10);

}