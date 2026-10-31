### Approach

Rotating by the list's length gives back the same list, so first reduce k modulo the length. The last k nodes then move to the front. With real nodes: link the tail to the head to form a ring, walk to the new tail (length - k - 1 steps from the head), and break the ring after it.

### Implementation

```python
from typing import List


class Solution:
    def rotateRight(self, head: List[int], k: int) -> List[int]:
        if not head:
            return []
        k %= len(head)
        return head[len(head) - k:] + head[:len(head) - k]
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
