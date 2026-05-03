class Solution {
public:
    bool isDivisor(int l, const string& str1, const string& str2) {
        int l1 = str1.size(), l2 = str2.size();
        string s1 = "", s2 = "";
        if (!((l1 % l == 0) && (l2 % l == 0))) return false;

        string sub = str1.substr(0, l);
        for (int i = 0 ; i < l1/l ; i++) s1 += sub;
        for (int i = 0 ; i < l2/l ; i++) s2 += sub;
        return (s1 == str1) && (s2 == str2);
    }
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size();
        for (int l = min(l1, l2); l > 0; l--) {
            if (isDivisor(l, str1, str2)) return str1.substr(0, l);
        }
        return "";
    }
};