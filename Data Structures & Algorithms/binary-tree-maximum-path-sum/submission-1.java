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
    private int result = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int res = splitPathSum(root);
        return Math.max(res, result);
    }
    private int splitPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = Math.max(splitPathSum(root.left), 0);
        int r = Math.max(splitPathSum(root.right), 0);
        result = Math.max(result, l + r + root.val);
        return Math.max(l, r) + root.val;
    }
}
