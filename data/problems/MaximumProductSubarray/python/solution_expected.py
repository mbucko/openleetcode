from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Track both the largest and smallest product of a subarray ending
        # at the current index: a negative number turns the smallest
        # (most negative) product into the largest one.
        max_ending_here = nums[0]
        min_ending_here = nums[0]
        best = nums[0]

        for value in nums[1:]:
            candidates = (value, max_ending_here * value, min_ending_here * value)
            max_ending_here = max(candidates)
            min_ending_here = min(candidates)
            best = max(best, max_ending_here)

        return best
