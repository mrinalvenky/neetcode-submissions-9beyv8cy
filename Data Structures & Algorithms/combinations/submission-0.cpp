class Solution {
public:
    void backTrack(int start, vector<int>& cur, vector<vector<int>>& res, int n,  int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for(int i = start; i <= n; i++) {
            cur.push_back(i);
            backTrack(i+1, cur, res, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backTrack(1, comb, res, n, k);
        return res;
        
    }
};