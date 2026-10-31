### Approach

Reverse just the sublist between the two positions. With real nodes: walk to the node before position left, then repeatedly take the node after the reversed section and move it to the front of that section, right - left times. The section ends up reversed and already connected at both ends, in one pass.

### Implementation

```python
from typing import List


class Solution:
    def reverseBetween(self, head: List[int], left: int, right: int) -> List[int]:
        return head[:left - 1] + head[left - 1:right][::-1] + head[right:]
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
