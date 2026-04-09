class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sm = numbers[i] + numbers[j];
            if (sm == target) {
                return new int[]{i+1, j+1};
            }
            if (sm < target) {
                i++;
            } else {
                j--;
            }
        } 
        return new int[]{-1, -1};
    }
}
