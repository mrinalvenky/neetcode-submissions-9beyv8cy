/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root, int max_val, int& cnt) {
        if (!root) return;
        if (root->val >= max_val) {
            cnt++;
            max_val = root->val;
        }
        helper(root->left, max_val, cnt);
        helper(root->right, max_val, cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        helper(root, INT_MIN, cnt);
        return cnt;
    }
};
