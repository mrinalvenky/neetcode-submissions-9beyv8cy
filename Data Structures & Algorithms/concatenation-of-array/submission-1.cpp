class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.size()*2);
        for (int i = 0; i < nums.size(); i++) {
            result[i + nums.size()] = result[i] = nums[i];
        }
        return result;
    }
};