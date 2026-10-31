from typing import List


class Solution:
    def deleteDuplicates(self, head: List[int]) -> List[int]:
        result = []
        for value in head:
            if not result or result[-1] != value:
                result.append(value)
        return result
