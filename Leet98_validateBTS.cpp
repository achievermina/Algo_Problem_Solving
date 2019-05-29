/*

Leetcode 98.Validate Binary Search Tree
Runtime error

*/


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool check;
        int rootNum = root->val;
        
        if(root->left==NULL && root->right==NULL){
            return true;
        }else{
        
            //check left
            TreeNode* checkLeft = root->left;
            TreeNode* checkRight = root->right;

            if(checkLeft!=NULL){
                if(checkLeft->val>rootNum)
                    return false;
                else
                    check = isValidBST(checkLeft); 
            }

            //check right
            if(checkRight!=NULL){
                if(checkRight->val<rootNum)
                    return false;
                else
                    check=isValidBST(checkRight);
            }
            
            return check;
        }
    }
};