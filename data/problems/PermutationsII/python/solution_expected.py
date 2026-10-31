from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        used = [False] * len(nums)
        current = []

        def build():
            if len(current) == len(nums):
                result.append(list(current))
                return
            for i, num in enumerate(nums):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                current.append(num)
                build()
                current.pop()
                used[i] = False

        build()
        return result
