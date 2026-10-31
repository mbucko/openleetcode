from typing import List


class Solution:
    def reverseBetween(self, head: List[int], left: int, right: int) -> List[int]:
        return head[:left - 1] + head[left - 1:right][::-1] + head[right:]
