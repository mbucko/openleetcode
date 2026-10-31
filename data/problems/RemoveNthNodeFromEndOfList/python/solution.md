### Approach

Use two pointers n nodes apart. Move the lead pointer n steps ahead, then move both until the lead reaches the end. The trailing pointer then sits on the node to remove. This finds it in a single pass without knowing the length in advance.

### Implementation

```python
from typing import List


class Solution:
    def removeNthFromEnd(self, head: List[int], n: int) -> List[int]:
        lead = n
        trail = 0
        while lead < len(head):
            lead += 1
            trail += 1
        return head[:trail] + head[trail + 1:]
```

### Complexity Analysis

* Time complexity: **O(sz)**.
* Space complexity: **O(1)**.
