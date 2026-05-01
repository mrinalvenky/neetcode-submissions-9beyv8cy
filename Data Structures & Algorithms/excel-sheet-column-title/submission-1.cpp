class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber) {
            columnNumber--;
            int rem = columnNumber % 26;
            res += ('A' + rem);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};