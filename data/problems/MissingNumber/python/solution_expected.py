from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        expected_total = n * (n + 1) // 2
        return expected_total - sum(nums)
