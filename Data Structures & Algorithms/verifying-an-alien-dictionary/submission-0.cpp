class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2) return true;
        if (order.size() < 26) return false;
        unordered_map<char, int> oMap;
        for (int i = 0; i < order.size(); i++) {
            oMap[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j == words[i+1].size()) return false;
                if (words[i][j] != words[i+1][j]) {
                    if (oMap[words[i + 1][j]] <  oMap[words[i][j]]) return false;
                    break;
                }
            }
        }
        return true;
    }
};