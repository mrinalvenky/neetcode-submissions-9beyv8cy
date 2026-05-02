class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        if (!nums.size()) return 0;
        while (true) {
            while (l < nums.size() && nums[l] != val) l++;
            while (r >= 0 && nums[r] == val) r--;
            if (l >= r) return l;
            swap(nums[l], nums[r]);
        }
        return -1;
    }
};