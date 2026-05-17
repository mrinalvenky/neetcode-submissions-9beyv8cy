class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size(), 0);
        int p1 = 0, p2 = 0, p = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                merged[p++] = nums1[p1++];
            } else {
                merged[p++] = nums2[p2++];
            }
        }
        while (p1 < nums1.size()) merged[p++] = nums1[p1++];
        while (p2 < nums2.size()) merged[p++] = nums2[p2++];
        return merged;
    }
    vector<int> mergeSort(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nums;
        }
        if (l == r) return {nums[l]};
        int mid = l + (r - l)/2;
        vector<int> m1 = mergeSort(nums, l , mid);
        vector<int> m2 = mergeSort(nums, mid+1, r);
        vector<int> merged = merge(m1, m2);
        return merged;
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};