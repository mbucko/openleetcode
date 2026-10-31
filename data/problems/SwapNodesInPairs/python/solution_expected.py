from typing import List


class Solution:
    def swapPairs(self, head: List[int]) -> List[int]:
        result = list(head)
        for i in range(0, len(result) - 1, 2):
            result[i], result[i + 1] = result[i + 1], result[i]
        return result
