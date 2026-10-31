### Approach

Two binary searches. The first finds the leftmost position whose value is at least target. If that value isn't target, it doesn't appear. Otherwise a second search finds the first position past target (the leftmost value greater than it), and the last occurrence sits just before that.

### Implementation

```python
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lower_bound(value):
            left, right = 0, len(nums)
            while left < right:
                mid = (left + right) // 2
                if nums[mid] < value:
                    left = mid + 1
                else:
                    right = mid
            return left

        first = lower_bound(target)
        if first == len(nums) or nums[first] != target:
            return [-1, -1]
        return [first, lower_bound(target + 1) - 1]
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
