class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
            }
        );
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;
        int i = 0;
        unordered_map<int, int> res;
        vector<int> result;
        for (const int& q: sortedQueries) {
            while(i < intervals.size() && intervals[i][0] <= q) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }
            res[q] = (!minHeap.empty()) ? minHeap.top().first : -1;
        }
        for (const int& q: queries) {
            result.push_back(res[q]);
        }
        return result;
    }
};
