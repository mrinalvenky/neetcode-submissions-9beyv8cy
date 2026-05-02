class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortString;
        int minlen = INT_MAX;
        for (string& s: strs) {
            if (s.size() < minlen) {
                shortString = s;
                minlen = s.size();
            }
        }
        string result = "";
        for (int i = 0; i < shortString.size(); i++) {
            for (string& s : strs) {
                if (s[i] != shortString[i]) return result;
            }
            result += shortString[i];
        }
        return result;
    }
};