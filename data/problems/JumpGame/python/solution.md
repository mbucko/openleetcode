### Approach

Scan left to right while tracking the farthest index reachable so far. If the scan ever reaches an index beyond that, the index can't be reached, and neither can anything after it.

### Implementation

```python
from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest = 0
        for i, step in enumerate(nums):
            if i > farthest:
                return False
            farthest = max(farthest, i + step)
        return True
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
