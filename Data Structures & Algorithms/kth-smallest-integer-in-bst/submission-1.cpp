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
    void inorder(TreeNode* root, int& cnt, int& res) {
        if (!root) return;
        if (cnt < 0) return;
        inorder(root->left, cnt, res);
        cnt--;
        if (cnt == 0) {
            res = root->val;
        }
        inorder(root->right, cnt, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = k, result = INT_MIN;
        inorder(root, count, result);
        return result;
    }
};
