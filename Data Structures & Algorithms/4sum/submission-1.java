class Solution {
    private List<List<Integer>> ksum(int start, int k, int[] nums, long target) {
        List<List<Integer>> ret = new ArrayList<>();
        if (k == 2) {
            int l = start, r = nums.length - 1;
            while(l < r) {
                long sum = nums[l] + nums[r];
                if (sum == target) {
                    ret.add(new ArrayList<>(Arrays.asList(nums[l], nums[r])));
                    l++; r--;
                    while (l > 0 && l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } else if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
            return ret;
        }

        k--;
        for (int i = start; i < nums.length; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            List<List<Integer>> kret = ksum(i + 1, k, nums, target - nums[i]);
            for (List<Integer> lst : kret) {
                List<Integer> cur = new ArrayList<>();
                cur.add(nums[i]);
                cur.addAll(lst);
                ret.add(cur);
            }
        }
        return ret;
    }
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        return ksum(0, 4, nums, target);
    }
}