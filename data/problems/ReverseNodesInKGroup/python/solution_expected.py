from typing import List


class Solution:
    def reverseKGroup(self, head: List[int], k: int) -> List[int]:
        result = list(head)
        for start in range(0, len(result) - k + 1, k):
            result[start:start + k] = reversed(result[start:start + k])
        return result
