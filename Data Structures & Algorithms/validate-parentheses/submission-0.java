class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> open = new HashMap<>();
        open.put('(', ')');
        open.put('[', ']');
        open.put('{', '}');

        for (Character c : s.toCharArray()) {
            if (open.containsKey(c)) {
                stack.push(c);
            } else if (c.equals(')') || c.equals('}') || c.equals(']')) {
                if (stack.isEmpty()) {
                    return false;
                }
                Character cl = stack.pop();
                if (!c.equals(open.get(cl))) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
