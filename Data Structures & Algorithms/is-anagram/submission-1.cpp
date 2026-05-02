class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap , tMap;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (!sMap.count(s[i])) {
                sMap[s[i]] = 0;
            } else {
                sMap[s[i]]++;
            }
            if (!tMap.count(t[i])) {
                tMap[t[i]] = 0;
            } else {
                tMap[t[i]]++;
            }
        }
        for (auto& [c, cnt] : sMap) {
            if (!tMap.count(c) || tMap[c] != cnt) return false;
        }
        return true;
    }
};
