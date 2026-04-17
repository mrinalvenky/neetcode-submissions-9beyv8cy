class MedianFinder {
    private Queue<Integer> smallHeap;
    private Queue<Integer> largeHeap;

    public MedianFinder() {
        smallHeap = new PriorityQueue<Integer>(
            (a, b) -> Integer.compare(b, a)
        );
        largeHeap = new PriorityQueue<Integer>(
            (a, b) -> Integer.compare(a, b)
        );
    }
    
    public void addNum(int num) {
        if (smallHeap.isEmpty() || num <= smallHeap.peek()) {
            smallHeap.offer(num);
        } else {
            largeHeap.offer(num);
        }

        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.offer(smallHeap.poll());
        } else if (largeHeap.size() > smallHeap.size()) {
            smallHeap.offer(largeHeap.poll());
        }
    }
    
    public double findMedian() {
        double s = smallHeap.isEmpty() ? 0.0 : smallHeap.peek(); 
        double l = largeHeap.isEmpty() ? 0.0 : largeHeap.peek();
        if (smallHeap.size() == largeHeap.size()) {
            return (s + l) /2;
        } else if (smallHeap.size() > largeHeap.size()) {
            return s;
        } else {
            return l;
        }
    }
}
