class MyQueue {
    Queue<Integer> stack1, stack2;
    public MyQueue() {
        stack1 = new ArrayDeque<>();
        stack2 = new ArrayDeque<>();
    }
    
    public void push(int x) {
        stack1.offer(x);
        while(stack1.size() > 0) {
            stack2.offer(stack1.poll());
        }
        Queue<Integer> temp = stack1;
        stack1 = stack2;
        stack2 = temp;
    }
    
    public int pop() {
        return stack1.poll();
    }
    
    public int peek() {
        return stack1.peek();
    }
    
    public boolean empty() {
        return stack1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */