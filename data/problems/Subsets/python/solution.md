### Approach

Sort the values and backtrack. Every partial selection is itself a subset, so record it as soon as you reach it, then try extending it with each later value. Recording before extending, and trying values in ascending order, produces the subsets in lexicographic order.

### Implementation

```python
from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        current = []

        def build(start):
            result.append(list(current))
            for i in range(start, len(nums)):
                current.append(nums[i])
                build(i + 1)
                current.pop()

        build(0)
        return result
```

### Complexity Analysis

* Time complexity: **O(n * 2^n)**.
* Space complexity: **O(n) recursion depth, besides the output**.
