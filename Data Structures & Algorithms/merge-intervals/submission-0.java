class Solution {
    public int[][] merge(int[][] intervals) {
        if ((intervals.length == 0) || (intervals[0].length == 0)) {
            return new int[0][0];
        }
        
        List<int[]> merged = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        merged.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int prevStart = merged.get(merged.size() - 1)[0];
            int prevEnd = merged.get(merged.size() - 1)[1];

            if (start <= prevEnd) {
                merged.remove(merged.size() - 1);
                merged.add(new int[]{prevStart, Math.max(end, prevEnd)});
            } else {
                merged.add(new int[]{start, end});
            }
        }
        int[][] result = new int[merged.size()][2];
        for (int i = 0; i < merged.size(); i++) {
            result[i][0] = merged.get(i)[0];
            result[i][1] = merged.get(i)[1];
        }
        return result;
    }
}
