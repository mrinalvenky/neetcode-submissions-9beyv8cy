class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            result.push_back(c);
            for (int n: adj[c]) {
                indegree[n]--;
                if (!indegree[n]) q.push(n);
            }
        }
        if (result.size() == numCourses) return result;
        return {};
    }
};
