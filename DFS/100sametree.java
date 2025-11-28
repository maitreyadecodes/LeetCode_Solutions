/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    /**
     * Checks if two binary trees are structurally identical and have the same node values.
     * @param p The root of the first tree.
     * @param q The root of the second tree.
     * @return true if the trees are the same, false otherwise.
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // 1. Base Case: Both nodes are null (reached the end of a branch simultaneously).
        // They are identical at this point.
        if (p == null && q == null) {
            return true;
        }

        // 2. Base Case: One node is null OR their values are different.
        // If one is null but the other is not, or if both exist but have different values,
        // the trees are NOT the same.
        if (p == null || q == null || p.val != q.val) {
            return false;
        }

        // 3. Recursive Step: Check the left subtrees AND the right subtrees.
        // The comparison only returns true if both recursive calls return true.
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}