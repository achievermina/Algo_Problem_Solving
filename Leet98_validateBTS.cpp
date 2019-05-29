

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return recursiveCheck(root, NULL, NULL);
    }
    
    bool recursiveCheck(TreeNode* node, int min, int max){
        if(node == NULL)
            return true;
        
        if( min !=NULL &&  node->val <= min )
            return false;
        if( max !=NULL && node->val >= max  )
            return false;
        
        
        return recursiveCheck(node->left, min, node->val) && recursiveCheck(node->right, node->val, max);
    }
};






/*

Leetcode 98.Validate Binary Search Tree
Runtime error

-- missed the case of 
    5
 1.     6
       4. 7
4<5 therefore, it should be on the left.

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