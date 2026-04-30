class Solution {
public:
    /*
    bool count01(vector<string>& cur, int m, int n) {
        int c_m = 0, c_n = 0;
        for (string s: cur) {
            for(char c: s) {
                if(c == '0') c_m++; else c_n++;
            }
        }
        return (c_m <= m && c_n <= n);
    }
    void findMaxFormHelper(int i, vector<string>& cur_set, int& max_size, vector<string>& strs, int m, int n) {
        if (i == strs.size()) {
            if (count01(cur_set, m, n)) {
                max_size = max(max_size, static_cast<int>(cur_set.size()));
            }
            return;
        }
        cur_set.push_back(strs[i]);
        findMaxFormHelper(i + 1, cur_set, max_size, strs, m, n);
        cur_set.pop_back();
        findMaxFormHelper(i + 1, cur_set, max_size, strs, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<string> c_set;
        int max_size = 0;
        findMaxFormHelper(0, c_set, max_size, strs, m, n);
        return max_size;
    }*/
    int dfs(int i, int m, int n, vector<string>& strs,
        vector<vector<vector<int>>>& memo) {
        if (i == strs.size()) return 0;

        if (memo[i][m][n] != -1) return memo[i][m][n];

        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            else ones++;
        }

        int skip = dfs(i + 1, m, n, strs, memo);

        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + dfs(i + 1, m - zeros, n - ones, strs, memo);
        }

        return memo[i][m][n] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(), 
                                        vector<vector<int>>(m + 1, 
                                        vector<int>(n + 1, -1)));
        return dfs(0, m, n, strs, memo);
    }
};