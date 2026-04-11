class Solution {
    public int maxProfit(int[] prices) {
        int l = 0, maxP = 0;
        for (int r = 1; r < prices.length ; r++) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = Math.max(maxP, profit);
            } else {
                l = r;
            }
        }
        return maxP;
    }
}
