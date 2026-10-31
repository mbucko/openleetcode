### Approach

Build a linked list from the input values. Walk it once with a pointer to the previous node: save the next node, point the current node back at the previous one, then move both pointers forward. When the walk ends, the previous pointer is the new head. Read the values from there into the output array.

### Implementation

```python
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
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n) to build the list and the output; the reversal itself uses O(1) extra space**.
