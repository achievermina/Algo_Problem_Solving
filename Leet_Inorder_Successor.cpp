
/*

Leetcode Inorder Successor in BST



*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        return recursiveLeftOrRight(root, p, 0, NULL);
    }
    
    TreeNode* recursiveLeftOrRight(TreeNode* root, TreeNode* p, int check, TreeNode* prev){
        


        if((root->val == p->val) && check == 0 )
            return NULL;
        if((root->val == p->val) && check == 1)
            return prev;
       
       
        if(root->val < p->val){
            recursiveLeftOrRight(root->right, p, 0, root);}
        if(root->val > p->val){
            recursiveLeftOrRight(root->left, p, 1, root);}
        
    }
    
};