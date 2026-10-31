from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> List[int]:
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return nums[:k]
