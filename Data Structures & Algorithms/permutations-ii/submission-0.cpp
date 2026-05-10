class Solution {
public:
    void backTrack(int index, vector<vector<int>>& res, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for(int i = index; i < nums.size(); i++) {
            if(seen.count(nums[i])) {
                continue;
            }
            seen.insert(nums[i]);
            swap(nums[index], nums[i]);
            backTrack(index + 1, res, nums);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backTrack(0, res, nums);
        return res;
    }
};