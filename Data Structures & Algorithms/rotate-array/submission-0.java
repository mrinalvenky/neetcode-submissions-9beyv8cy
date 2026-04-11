class Solution {
    private void reverse(int[] nums, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
    }
    public void rotate(int[] nums, int k) {
        k = k % nums.length;

        reverse(nums, 0, (nums.length - 1));
        reverse(nums, 0, k - 1);
        reverse(nums, k, (nums.length - 1));
        
    }
}