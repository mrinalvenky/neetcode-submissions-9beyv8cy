class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (string& str: strs) {
            vector<int> count(26, 0);
            for (char c: str) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1 ; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& [key, value]: res) {
            result.push_back(value);
        }
        return result;
    }
};
