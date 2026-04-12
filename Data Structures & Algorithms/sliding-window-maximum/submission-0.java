class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        int[] output = new int[nums.length - k + 1];
        int l = 0;
        for (int r = 0; r < nums.length; r++) {
            while (!q.isEmpty() && nums[q.peekLast()] < nums[r]) {
                q.pollLast();
            }
            q.offer(r);
            if (l > q.peek()) {
                q.poll();
            }
            if ((r + 1) >= k) {
                output[l] = nums[q.peek()];
                l++;
            }
        }
        return output;
    }
}
