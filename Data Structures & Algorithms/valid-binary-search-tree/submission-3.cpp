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
 *                5
          4 (N,5)           7
        1(N,4)  10(4, 5)         6 9
        1 (N, X)
       2(N,1) 3
 */

class Solution {
public:
    bool dfs(TreeNode* root, int l, int h) {
        if (!root) return true;
        if (root->val <= l || root->val >= h) return false;
        return dfs(root->left, l, root->val) &&
               dfs(root->right, root->val, h);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
