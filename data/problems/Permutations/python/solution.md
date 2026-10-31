### Approach

Sort the values, then backtrack: at each position, try every value not yet used, recurse, then undo. Trying values in ascending order at every position produces the permutations in lexicographic order.

### Implementation

```python
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        used = [False] * len(nums)
        current = []

        def build():
            if len(current) == len(nums):
                result.append(list(current))
                return
            for i, num in enumerate(nums):
                if not used[i]:
                    used[i] = True
                    current.append(num)
                    build()
                    current.pop()
                    used[i] = False

        build()
        return result
```

### Complexity Analysis

* Time complexity: **O(n * n!)**.
* Space complexity: **O(n) recursion depth, besides the output**.
