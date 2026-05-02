class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap , tMap;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        for (auto& [c, cnt] : sMap) {
            if (!tMap.count(c) || tMap[c] != cnt) return false;
        }
        return true;
    }
};
