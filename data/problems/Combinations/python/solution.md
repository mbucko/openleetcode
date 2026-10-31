### Approach

Backtracking. Pick numbers in increasing order, each larger than the last one picked. Stop the loop early once there aren't enough numbers left to complete the combination. Choosing in increasing order gives the lexicographic ordering for free.

### Implementation

```python
from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        current = []

        def build(start):
            if len(current) == k:
                result.append(list(current))
                return
            for value in range(start, n - (k - len(current)) + 2):
                current.append(value)
                build(value + 1)
                current.pop()

        build(1)
        return result
```

### Complexity Analysis

* Time complexity: **O(k * C(n, k))**.
* Space complexity: **O(k) recursion depth, besides the output**.
