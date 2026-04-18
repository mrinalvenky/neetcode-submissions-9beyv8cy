class Solution {
    private List<List<Integer>> result;
    private void backTrack(int[] nums, int idx, List<Integer> subset) {
        if (idx == nums.length) {
            result.add(new ArrayList<>(subset));
            return;
        }
        subset.add(nums[idx]);
        backTrack(nums, idx + 1, subset);
        subset.remove(subset.size() - 1);
        backTrack(nums, idx + 1, subset);   
    }
    public List<List<Integer>> subsets(int[] nums) {
        result = new ArrayList<>();
        backTrack(nums, 0, new ArrayList<>());
        return result;
    }
}
