class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        n_set = set(nums)
        mx = 1
        for n in nums:
            if (n - 1) not in n_set:
                cnt = 1
                t  = n + 1
                while t in n_set:
                   cnt += 1
                   t += 1
                mx = max(cnt, mx)
        return mx 
                   
        