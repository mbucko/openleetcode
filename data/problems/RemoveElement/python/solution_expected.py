from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> List[int]:
        k = 0
        for num in nums:
            if num != val:
                nums[k] = num
                k += 1
        return nums[:k]
