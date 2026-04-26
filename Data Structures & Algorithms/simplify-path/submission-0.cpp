class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token, result;
        vector<string> st;
        while (getline(ss, token, '/')) {
            if (token == "." || token == "") continue;
            else if (token == "..") {
                if (st.size() > 0) st.pop_back();
            }
            else st.push_back(token);
        }
        if (st.size() == 0) return "/";
        for (const string& s: st) {
            result += "/" + s;
        }
        return result;
    }
};