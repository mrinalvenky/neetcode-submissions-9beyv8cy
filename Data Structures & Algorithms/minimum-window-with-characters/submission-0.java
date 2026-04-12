class Solution {
    public String minWindow(String s, String t) {
        if (t.isEmpty()) return "";
        Map<Character, Integer> tSet = new HashMap<>();
        Map<Character, Integer> sSet = new HashMap<>();
        int have = 0, need = 0, l = 0, minLen = Integer.MAX_VALUE;
        int[] res = {-1, -1};
        for (int i = 0; i < t.length(); i++) {
            tSet.put(t.charAt(i), 1 + tSet.getOrDefault(t.charAt(i), 0));
        }
        need = tSet.size();

        for (int r = 0; r < s.length() ; r++) {
            char rchar = s.charAt(r);
            sSet.put(rchar, 1 + sSet.getOrDefault(rchar, 0));
            if (tSet.containsKey(rchar) && tSet.get(rchar) == sSet.get(rchar)) {
                have++;
            }
            while (have == need) {
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    res[0] = l;
                    res[1] = r;
                }
                char lchar = s.charAt(l);
                sSet.put(lchar, sSet.get(lchar) - 1);
                if (tSet.containsKey(lchar) && sSet.get(lchar) < tSet.get(lchar)) {
                    have--;
                }
                l++;
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(res[0], res[1] + 1);
    }
}
