from typing import List


class Solution:
    def removeNthFromEnd(self, head: List[int], n: int) -> List[int]:
        lead = n
        trail = 0
        while lead < len(head):
            lead += 1
            trail += 1
        return head[:trail] + head[trail + 1:]
