class Solution {
private:
    string helper(int& i, string& s){
        int k = 0;
        string res; 
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                i++;
                string sub_str = helper(i, s);
                while(k-- > 0) res += sub_str;
                k = 0;
            } else if (c == ']') {
                return res;
            } else {
                res.push_back(c);
            }

            i++;
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return helper(i, s);   
    }
};