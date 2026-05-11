class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int x) {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool unionSet(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        if (p1 == p2) {
            return false;
        }
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU uf(n);
        unordered_map<string , int> emailToAcc;
        for (int i = 0; i < n ; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (emailToAcc.count(accounts[i][j])) {
                    uf.unionSet(i, emailToAcc[accounts[i][j]]);
                } else {
                    emailToAcc[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> emailGroup; 
        for (const auto& [email, accId] : emailToAcc) {
            int leader = uf.find(accId);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> res;
        for (auto& [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            for (string& e: emails) {
                merged.push_back(e);
            }
            res.push_back(merged);
        }
        return res;
    }
};