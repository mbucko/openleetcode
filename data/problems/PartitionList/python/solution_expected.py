from typing import List


class Solution:
    def partition(self, head: List[int], x: int) -> List[int]:
        before = [v for v in head if v < x]
        after = [v for v in head if v >= x]
        return before + after
