class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, vector<int>>> maxHeap;
        for (auto& p: points) {
            long long dist = p[0] * p[0] + p[1] * p[1];
            maxHeap.push({dist, p});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
