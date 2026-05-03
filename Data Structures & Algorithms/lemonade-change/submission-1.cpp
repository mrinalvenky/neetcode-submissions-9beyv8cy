class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5 = 0, b10 = 0;
        for (int b: bills) {
            if (b == 5) {
                b5++;
            }
            else if (b == 10) {
                if (b5 == 0) return false;
                b5--;
                b10++;
            } else { // 20
                if (b10 > 0) {
                    if (b5 == 0) return false;
                    b10--; b5--;
                } else if (b10 == 0) {
                    if (b5 < 3) return false;
                    b5 -= 3;
                }
            }
        }
        return true;
    }
};