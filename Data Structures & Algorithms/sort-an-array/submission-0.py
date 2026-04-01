class Solution:
    def mergeTwoArrays(self, nums:List[int], L:int, M:int, H:int):
        m1, m2 = nums[L:M+1], nums[M+1:H+1]
        i , j, k = 0, 0, L
        while i < len(m1) and j < len(m2):
            if m1[i] < m2[j]:
                nums[k] = m1[i]
                i += 1
                k += 1
            else:
                nums[k] = m2[j]
                j += 1
                k += 1
        while i < len(m1):
            nums[k] = m1[i]
            i += 1
            k += 1
        while j < len(m2):         
            nums[k] = m2[j]
            j += 1
            k += 1
        return nums
    
    def mergeSort(self, nums:List[int], low:int, high:int) -> List[int]:
        if low >= high:
            return nums
        mid = (low + high)//2
        self.mergeSort(nums, low, mid)
        self.mergeSort(nums, mid+1, high)
        return self.mergeTwoArrays(nums, low, mid, high)
    
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.mergeSort(nums, 0, len(nums) - 1)