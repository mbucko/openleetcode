from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        current = []

        def build(start):
            result.append(list(current))
            for i in range(start, len(nums)):
                current.append(nums[i])
                build(i + 1)
                current.pop()

        build(0)
        return result
