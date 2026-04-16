/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public boolean isBoundedValidBST(TreeNode root, Integer left, Integer right) {
        if (root == null) return true;

        if (!(root.val > left && root.val < right)) {
            return false;
        }

        return isBoundedValidBST(root.left, left, root.val) && 
               isBoundedValidBST(root.right, root.val, right);

    }
    public boolean isValidBST(TreeNode root) {
        return isBoundedValidBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}
