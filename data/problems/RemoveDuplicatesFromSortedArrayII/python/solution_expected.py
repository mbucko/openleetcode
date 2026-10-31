from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> List[int]:
        k = 0
        for num in nums:
            if k < 2 or num != nums[k - 2]:
                nums[k] = num
                k += 1
        return nums[:k]
