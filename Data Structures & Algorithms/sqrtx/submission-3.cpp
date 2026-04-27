class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x;
        while (l <= r) {
            int mid = l + (r - l)/2;
            long long p = 1LL * mid * mid;
            if (p == x) return mid;
            if (p > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};