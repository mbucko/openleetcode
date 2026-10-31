### Approach

Binary search for the first index whose value is at least target. That is target's index if it is present, and its insertion point otherwise.

### Implementation

```python
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
