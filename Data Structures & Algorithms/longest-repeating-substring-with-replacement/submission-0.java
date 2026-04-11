class Solution {
    public int characterReplacement(String s, int k) {
        int res = 0, l = 0;
        Map<Character, Integer> fmap = new HashMap<>();

        for (int r = 0; r < s.length() ; r++) {
            fmap.put(s.charAt(r), 1 + fmap.getOrDefault(s.charAt(r), 0));
            int maxf = 0;
            for (Integer f : fmap.values()) {
                maxf = Math.max(f, maxf);
            }
            int numRep = (r - l + 1) - maxf;
            if (numRep <= k) {
                res = Math.max((r - l + 1), res);
            }
            while ((r - l + 1) - maxf > k) {
                fmap.put(s.charAt(l), fmap.get(s.charAt(l)) - 1);
                l++;
            }
        }
        return res;   
    }
}
