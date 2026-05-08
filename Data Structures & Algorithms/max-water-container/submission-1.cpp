class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxAr = 0;
        while (l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            maxAr = max(maxAr, area);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxAr;
    }
};
