class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidate1 = None
        candidate2 = None
        count1 = 0
        count2 = 0
        for n in nums:
            if n == candidate1:
                count1 += 1
            elif n == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = n
                count1 = 1
            elif count2 == 0:
                candidate2 = n
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        res = []
        if nums.count(candidate1) > (len(nums)//3):
            res.append(candidate1)
        if candidate2 != candidate1 and nums.count(candidate2) > (len(nums)//3):
            res.append(candidate2)
        return res

        