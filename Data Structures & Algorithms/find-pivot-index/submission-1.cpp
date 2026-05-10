class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), prefix = 0;
        vector<int> postfix(n, 0);
        postfix[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = nums[i] + postfix[i+1];
        }
        for (int i = 0; i < n - 1; i++) {
            if (prefix == postfix[i + 1]) return i;
            prefix += nums[i];
        }
        if (0 == prefix) return (n-1);
        return -1;
    }
};