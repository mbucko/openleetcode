### Approach

Sort the values and backtrack as for Subsets, recording every partial selection. To avoid repeats, skip a value at a given depth if it equals the value tried just before it at the same depth. The first copy already led to every subset that copy could start.

### Implementation

```python
from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        current = []

        def build(start):
            result.append(list(current))
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                current.append(nums[i])
                build(i + 1)
                current.pop()

        build(0)
        return result
```

### Complexity Analysis

* Time complexity: **O(n * 2^n)**.
* Space complexity: **O(n) recursion depth, besides the output**.
