//
//  21.cpp
//  algo
//
//  Created by Mina on 24/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
    const int N =preorder.size();
    
    //Base case
    if(preorder.empty()) return;
    
    //find the root
    int root = preorder[0];
    
    int left, right;
    //find the size of left tree
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i]==root){
            left = i;
            break;
        }
    }
    
    right = N-left -1;
    
    //print Left
    printPostOrder(vector<int>(preorder.begin()+1, preorder.begin()+left+1), vector<int>(inorder.begin()+0, inorder.begin()+left));
    //print Right
    printPostOrder(vector<int>(preorder.begin()+left+1, preorder.begin()+N), vector<int>(inorder.begin()+left+1, inorder.begin()+N));
    //print Root
    cout<<root<<"\t";
    
}


int main(){
    
    //Testcase 1

//    7
//    27 16 9 12 54 36 72
//    9 12 16 27 36 54 72
    
    vector<int>pre ={27, 16, 9, 12, 54, 36, 72};
    vector<int>in ={9, 12, 16, 27, 36, 54, 72};

    printPostOrder(pre, in);
    
   
    //Testcase 2
    
//    6
//    409 479 10 838 150 441
//    409 10 479 150 838 441
}
