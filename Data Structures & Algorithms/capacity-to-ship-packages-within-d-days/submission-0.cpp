class Solution {
public:
    int daysTaken(vector<int>& weights, int tot, int wt) {
        int curwt = 0, days = 1;
        for (int w : weights) {
            if (curwt + w > wt) {
                days++;
                curwt = 0;
            }
            curwt += w;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0], r = 0, tot = 0;
        for (int w: weights) {
            l = max(l, w);
            tot += w;
        }
        r = tot;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (daysTaken(weights, tot, mid) <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};