class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        int op2, op1;
        for (String o: tokens) {
            switch(o) {
                case "+":
                    op2 = stack.pop();
                    op1 = stack.pop();
                    stack.push(op2 + op1);
                    break;
                case "-":
                    op2 = stack.pop();
                    op1 = stack.pop();
                    stack.push(op1 - op2);
                    break;
                case "*":
                    op2 = stack.pop();
                    op1 = stack.pop();
                    stack.push(op2 * op1);
                    break;
                case "/":
                    op2 = stack.pop();
                    op1 = stack.pop();
                    stack.push(op1 / op2);
                    break;
                default:
                    stack.push(Integer.parseInt(o));
                    break;
            }
        }
        return stack.pop();
    }
}
