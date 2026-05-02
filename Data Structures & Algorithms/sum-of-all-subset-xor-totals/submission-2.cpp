class Solution {
public:
    void backtrack(int idx, int curXor, long long& result, vector<int>& nums) {
        if (idx == nums.size()) {
            result += curXor;
            return; 
        }
        backtrack(idx + 1, curXor ^ nums[idx], result, nums);
        backtrack(idx + 1, curXor, result, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        long long result = 0;
        backtrack(0, 0, result, nums);
        return result;
    }
};