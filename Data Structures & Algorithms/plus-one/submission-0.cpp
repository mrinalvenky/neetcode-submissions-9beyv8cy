class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, l = digits.size();
        vector<int> result(l);
        // reverse(digits.begin(), digits.end());
        for (int i = 0; i < l; i++) {
            int s = digits[l - i - 1] + carry;
            carry = s / 10;
            result[i] = s % 10;
        }
        if (carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
