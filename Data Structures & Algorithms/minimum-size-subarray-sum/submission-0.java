class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0, minLen = Integer.MAX_VALUE;
        int curSum = 0;
        for (int r = 0; r < nums.length; r++) {
            curSum += nums[r];
            while (curSum >= target) {
                minLen = Math.min(minLen, (r - l + 1));
                curSum -= nums[l];
                l++;
            }
        }
        if (minLen == Integer.MAX_VALUE) return 0;
        return minLen;
    }
}