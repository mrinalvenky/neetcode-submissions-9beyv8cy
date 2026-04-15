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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return root;
        }
        /*root.right = invertTree(root.left);
        root.left = invertTree(root.right);
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;*/

        // Iterative DFS
        /*Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while(!stack.isEmpty()) {
            TreeNode node = stack.pop();
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
            if (node.left != null) stack.push(node.left);
            if (node.right != null) stack.push(node.right);
        }*/

        // Iterative BFS
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
        return root;
    }
}
