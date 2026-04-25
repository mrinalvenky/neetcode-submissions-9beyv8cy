class StockSpanner {
    List<Integer> backDate;
    public StockSpanner() {
        backDate = new ArrayList<>();
    }
    
    public int next(int price) {
        int res = 0;
        backDate.add(price);
        int i = backDate.size() - 1;
        while (i >= 0 && backDate.get(i--) <= price) {
            res++;
        }
        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */