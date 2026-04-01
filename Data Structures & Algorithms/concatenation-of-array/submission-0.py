class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = [0] * (2 * len(nums))
        for i, n in enumerate(nums):
            ans[i] = n
            ans[i + len(nums)] = n
        return ans

        