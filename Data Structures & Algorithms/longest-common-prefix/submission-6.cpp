class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string shortString = *min_element(
            strs.begin(),
            strs.end(),
            [](const string& a, const string& b) {
                return a.size() < b.size();
            }
        );
        for (int i = 0; i < shortString.size(); i++) {
            for (string& s : strs) {
                if (s[i] != shortString[i]) return shortString.substr(0, i);
            }
        }
        return shortString;
    }
};