from typing import List


class Solution:
    def rotateRight(self, head: List[int], k: int) -> List[int]:
        if not head:
            return []
        k %= len(head)
        return head[len(head) - k:] + head[:len(head) - k]
