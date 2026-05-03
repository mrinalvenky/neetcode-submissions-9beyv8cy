class Solution {
public:
    int square(int m) {
        int result = 0;
        while (m) {
            int rem = m % 10;
            result += rem * rem;
            m = m / 10;
        }
        return result;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        int s = n;
        while(s != 1) {
            s = square(s);
            if (seen.count(s)) return false;
            seen.insert(s);
        }
        return true;
    }
};
