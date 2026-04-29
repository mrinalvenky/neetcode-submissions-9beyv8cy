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
    bool isSametree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;
        return isSametree(p->left, q->left) && isSametree(p->right, q->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && subRoot) return false;
        if (!subRoot) return true;
        return isSametree(root, subRoot) || 
               isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }
};
