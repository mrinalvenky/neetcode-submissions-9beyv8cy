class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0 , slow = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }
        int slow2 = 0;
        while (true) {
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow2 == slow) return slow;
        }
        return -1;
    }
};
