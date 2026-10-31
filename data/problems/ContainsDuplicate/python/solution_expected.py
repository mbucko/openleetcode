from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dup = set()

        for num in nums:
            if num in dup:
                return True
            dup.add(num)

        return False
