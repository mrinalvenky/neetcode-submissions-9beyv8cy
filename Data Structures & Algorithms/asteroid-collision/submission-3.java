class Solution {
    public int[] asteroidCollision(int[] asteroids) {
    Deque<Integer> stack = new ArrayDeque<>();

    for (int a : asteroids) {
        boolean alive = true;

        while (alive && a < 0 && !stack.isEmpty() && stack.peek() > 0) {
            int top = stack.peek();

            if (top < -a) {
                stack.pop();      // top explodes, current asteroid continues
            } else if (top == -a) {
                stack.pop();      // both explode
                alive = false;
            } else {
                alive = false;    // current asteroid explodes
            }
        }

        if (alive) {
            stack.push(a);
        }
    }

    int[] result = new int[stack.size()];
    for (int i = result.length - 1; i >= 0; i--) {
        result[i] = stack.pop();
    }

    return result;
    }
}