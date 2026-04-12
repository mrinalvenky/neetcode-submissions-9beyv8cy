class Solution {
    public int calPoints(String[] operations) {
        Deque<Integer> stack = new ArrayDeque<>();
        int result = 0;
        for (String op: operations) {
            switch (op) {
                case "+" :
                    int op2 = stack.pop();
                    int op1 = stack.peek();
                    stack.push(op2);
                    stack.push(op1 + op2);
                    break;
                case "C":
                    stack.pop();
                    break;
                case "D":
                    int t = stack.peek();
                    stack.push(2 * t);
                    break;
                default:
                    stack.push(Integer.parseInt(op));
            }
        }
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
}