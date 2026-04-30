/*
n -> length of array
t -> target
             *
           +2   -2
          4 0   0 -4
memo[0 - n][-t to +t]

*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       vector<unordered_map<int, int>> dp(nums.size() + 1);
       dp[0][0] = 1;
       for (int i = 0; i < nums.size(); i++) {
            for (const auto& [cur_sum, count] : dp[i]) {
                dp[i+1][cur_sum + nums[i]] += count;
                dp[i+1][cur_sum - nums[i]] += count;
            }
       }
       return dp[nums.size()][target];
    }
};
