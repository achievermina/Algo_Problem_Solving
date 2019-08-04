/*

Leet322_CoinChange

Dynamic programming

*/

//Brute Force
//using Recursive call


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int coinChange(vector<int>& coins, int amount){
    
    int mem[amount+1];
    mem[0]=0;
    
    sort(coins.begin(), coins.end());
    
    for(int currentAmount =1; currentAmount<=amount; currentAmount++){
        mem[currentAmount] = 1000000000;
        for(int i=0; i< coins.size(); ++i){
            if(currentAmount>= coins[i] && mem[currentAmount-coins[i]]!=-1){
                mem[currentAmount] = min( mem[currentAmount-coins[i]]+1, mem[currentAmount]);
            }
        }
        if(mem[currentAmount] == 1000000000)
            mem[currentAmount] =-1;
    }
    return mem[amount];
}


int main(){
    vector<int> eg = {2};
    int amount =3;
    
    cout<<coinChange(eg, amount);
    
    
}
