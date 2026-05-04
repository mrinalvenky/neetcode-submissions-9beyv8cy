class Solution {
public:
    unordered_set<int>& dfs(int c, vector<vector<int>>& adj, unordered_map<int,unordered_set<int>>& mp) {
        if (!mp.count(c)) {
            for (int nei : adj[c]) {
                mp[c].insert(nei);
                auto& ret = dfs(nei, adj, mp);
                for (int s: ret){
                    mp[c].insert(s);
                }
            }
        }
        return mp[c];
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for (auto& p: prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        unordered_map<int,unordered_set<int>> mp;
        for (int i = 0; i < numCourses; i++) {
            dfs(i, adj, mp);
        }
        vector<bool> result;
        for (auto& q: queries) {
            if (mp[q[0]].count(q[1])) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};