### Approach

Step through the list one group of k nodes at a time, and stop when fewer than k nodes remain. Reverse each full group in place. With real nodes, that means reversing the group's links and attaching the reversed group to the previous group and to the rest of the list.

### Implementation

```python
from typing import List


class Solution:
    def reverseKGroup(self, head: List[int], k: int) -> List[int]:
        result = list(head)
        for start in range(0, len(result) - k + 1, k):
            result[start:start + k] = reversed(result[start:start + k])
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
