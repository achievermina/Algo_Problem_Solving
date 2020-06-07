import javax.swing.tree.TreeNode;

public class Leet222_CountCompleteTreeNodes {

    public int countNodes(TreeNode root) {
        if (root == null) return 0;

        return recursiveCount(root);

    }

    private int recursiveCount(TreeNode cur) {
        int count = 1;
        if(cur.left == null && cur.right == null) {
            return 1;
        }

        if(cur.left != null) count += recursiveCount(cur.left);
        if(cur.right != null) count += recursiveCount(cur.right);

        return count;
    }

}
