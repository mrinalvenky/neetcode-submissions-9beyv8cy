class Solution { 
    private void backTrack(int idx, int curSum, List<Integer> combination, 
                           int target, int[] nums, List<List<Integer>> result) {
        if (curSum == target) {
            result.add(new ArrayList<>(combination));
            return;
        }
        if (curSum > target || idx >= nums.length) {
            return;
        }
        combination.add(nums[idx]);
        backTrack(idx, curSum + nums[idx], combination, target, nums, result);
        combination.remove(combination.size() - 1);
        backTrack(idx + 1, curSum, combination, target, nums, result);
    }
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        backTrack(0, 0, new ArrayList<>(), target, nums, result);
        return result;
    }
}
