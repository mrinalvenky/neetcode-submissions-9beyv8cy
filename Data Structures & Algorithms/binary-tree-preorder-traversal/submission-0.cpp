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
    /*void helper(vector<int>& res, TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        helper(res, root->left);
        helper(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(result, root);
        return result;
    }*/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (!root) return result;
        TreeNode *cur = root;
        st.push(cur);
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        return result;
    }
};