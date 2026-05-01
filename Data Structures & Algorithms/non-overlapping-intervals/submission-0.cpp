class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b) {
                return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
            }
        );
        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end <= intervals[i][0]) {
                prev_end = intervals[i][1];
            } else {
                count++;
                prev_end = min(prev_end, intervals[i][1]);
            }
        }
        return count;
    }
};
