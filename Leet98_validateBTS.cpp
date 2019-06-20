

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return true;
        
        return recursiveCheck(root, -999999999, 99999999999);
    }
    
    bool recursiveCheck(TreeNode* node, int min, int max){
        if(node == NULL )
            return true;
        
        if( node->val <= min )
            return false;
        if( node->val >= max  )
            return false;
        
        
        return recursiveCheck(node->left, min, node->val) && recursiveCheck(node->right, node->val, max);
    }
};



/*
 Modified version
 #define NULL 0
 min max are 0 -->  we cannot work with negative values
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return checkNode(root, INT_MIN, INT_MAX);
    }
    
    bool checkNode(TreeNode* node, long long min, long long max){
        if (node == NULL) {
            return true;
        }
        
        if (!(min <= node->val && node->val <= max)) {
            return false;
        }
        
        return checkNode(node->left, min, (long long)node->val - 1) &&
        checkNode(node->right, (long long)node->val + 1, max);
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
