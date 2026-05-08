class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : nums) {
            if (!numSet.count(num - 1)) {
                int cur  = num;
                int count = 0;
                while(numSet.count(cur)) {
                    cur++;
                    count++;
                }
                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};
