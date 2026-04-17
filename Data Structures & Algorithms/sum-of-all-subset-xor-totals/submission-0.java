class Solution {
    private int backtrack(int[] nums, int idx, int subSetXor) {
        if (idx == nums.length) {
            return subSetXor;
        }
        return backtrack(nums, idx + 1, subSetXor ^ nums[idx]) + 
        backtrack(nums, idx + 1, subSetXor);
    }
    public int subsetXORSum(int[] nums) {
        return backtrack(nums, 0, 0);
    }
}