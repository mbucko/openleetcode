### Approach

Walk the list two nodes at a time and swap each pair. With real nodes this means relinking: the node before the pair points to the second node, the second points to the first, and the first points to whatever followed the pair.

### Implementation

```python
from typing import List


class Solution:
    def swapPairs(self, head: List[int]) -> List[int]:
        result = list(head)
        for i in range(0, len(result) - 1, 2):
            result[i], result[i + 1] = result[i + 1], result[i]
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
