class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);

        for (auto& interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            int prev_end = result.back()[1];

            if (prev_end < start) {
                result.push_back(interval);
            } else {
                result.back()[1] = max(end, prev_end);
            }
        }
        return result;
    }
};
