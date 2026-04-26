class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> st;
        int maxArea = 0, lastIdx = 0;
        for (int i = 0; i < heights.size(); i++) {
            lastIdx = i;
            while (!st.empty() && st.back().first > heights[i]) {
                int area = (i - st.back().second) * st.back().first;
                maxArea = max(maxArea, area);
                lastIdx = st.back().second;
                st.pop_back();
            }
            st.push_back({heights[i], lastIdx});
        }
        lastIdx = heights.size();
        while (!st.empty()) {
            int area = (lastIdx - st.back().second) * st.back().first;
            maxArea = max(maxArea, area);
            st.pop_back();
        }
        return maxArea;
    }
};
