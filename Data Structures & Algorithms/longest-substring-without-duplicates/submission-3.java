class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0, maxL = 0;
        Set<Character> window = new HashSet<>();

        for (int r = 0; r < s.length(); r++) {
            while (window.contains(s.charAt(r))) {
                window.remove(s.charAt(l));
                l++;
            }
            window.add(s.charAt(r));
            maxL = Math.max(maxL, r - l + 1);
        }

        return maxL;
    }
}
