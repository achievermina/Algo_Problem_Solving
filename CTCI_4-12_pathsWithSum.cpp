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

int total=0;

int countPathsWithSum(TreeNode* node, int targetSum){
    int sum=0;
    
    //Recursive sum
    TreeNode* cur;
    
    //base case
    if(root-> right == NULL && root-> left ==NULL) return sum+node->val;
    
    
    //Check the sum
    if(sum==targetSum) total++;
    
    
    
    
    
}



int main() {

    return 0;
}
