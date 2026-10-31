from typing import List, Optional


class ListNode:
    def __init__(self, val: int = 0, next: "Optional[ListNode]" = None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: List[int]) -> List[int]:
        dummy = ListNode()
        tail = dummy
        for value in head:
            tail.next = ListNode(value)
            tail = tail.next

        prev = None
        curr = dummy.next
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        result = []
        while prev:
            result.append(prev.val)
            prev = prev.next
        return result