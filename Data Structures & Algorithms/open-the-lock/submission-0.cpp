class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        q.push("0000");
        int level = 0;
        while(!q.empty()) {
            int size = static_cast<int>(q.size());
            for(int i = 0; i < size; i++) {
                string lock = q.front();
                q.pop();
                if (lock == target) return level;
                for (int j = 0; j < 4; j++) {
                    string up = lock;
                    up[j] = ((lock[j] - '0' + 1) % 10) + '0';
                    if (!visited.count(up)) {
                        visited.insert(up);
                        q.push(up);
                    }
                    string down = lock;
                    down[j] = (lock[j] == '0') ? '9' : (lock[j] - '0' - 1) + '0';
                    if (!visited.count(down)) {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};