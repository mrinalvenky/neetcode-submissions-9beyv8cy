class Solution {
    public void reverseString(char[] s) {
        /*int i = 0, j = s.length - 1;
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }*/
        Deque<Character> stack = new ArrayDeque<Character>();
        for (char c : s) {
            stack.push(c);
        }
        for (int i = 0; i < s.length; i++) {
            s[i] = stack.pop();
        }
    }
}