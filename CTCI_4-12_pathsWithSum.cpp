//
//  main.cpp
//  algo
//
//  Created by Mina on 13/07/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
using namespace std;

//Brute Force
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Traverse Each Node

//Recursively try all paths, find the target sum -> Increase the total
//Brute Force
int count=0;
int sum=0;

void countPathsWithSum(TreeNode* node, int targetSum){

    
    //Recursive sum
    TreeNode* cur;
    
    //Base case
    if(node==NUll) return 0;
    
    //Check the sum
    if(targetSum - node->val ==0) count++;
    
    countPathsWithSum(root-> right, targetSum-(node->val));
    countPathsWithSum(root-> left, targetSum-(node->val));
    
    
}



int main() {

    return 0;
}
