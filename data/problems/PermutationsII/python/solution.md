### Approach

Sort the values and backtrack as for distinct values, with one extra rule: copies of the same value are always used in their original order. A copy may only be picked once the copy before it is already in use. That rules out orderings that differ only in which copy sits where.

### Implementation

```python
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        used = [False] * len(nums)
        current = []

        def build():
            if len(current) == len(nums):
                result.append(list(current))
                return
            for i, num in enumerate(nums):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
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
