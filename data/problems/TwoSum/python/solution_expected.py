from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited = {}

        for index, value in enumerate(nums):
            delta = target - value
            if delta in visited:
                return [visited[delta], index]
            visited[value] = index

        return []
