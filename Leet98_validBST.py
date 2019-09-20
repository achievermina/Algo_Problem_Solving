# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        if(root==None):
            return True;
        

        def DFS(cur, maximum, minimum):
            
            if(cur==None):
                return True;
            
            if(cur.val <= minimum or cur.val >= maximum):
                return False;
            
            return DFS(cur.left, cur.val, minimum) and DFS(cur.right, maximum, cur.val)
            
        return DFS(root.left, root.val, float('-inf')) and DFS(root.right, float('inf'), root.val)

              
