class Solution {
    public int hammingWeight(int n) {
        int hw = 0;
        while (n > 0) {
            hw += (n & 0x1);
            n >>= 1;
        }
        return hw;
    }
}
